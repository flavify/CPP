#include "PmergeMe.hpp"
#include <stdexcept>
#include <iterator>
#include <numeric>

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv) {
  if (argc < 2) {
    throw std::invalid_argument("Error: No input provided.");
  }

  for (int i = 1; i < argc; ++i) {
    try {
      int nb = std::stoi(argv[i]);
      if (nb < 0) {
        throw std::invalid_argument("Error: Negative number encountered.");
      }
      _input.push_back(static_cast<ValueType>(nb));
    } catch (...) {
      throw std::invalid_argument("Error: Non-integer input encountered.");
    }
  }

  _hasStraggler = (_input.size() % 2 != 0);
  if (_hasStraggler) {
    _straggler = _input.back();
  }
}

template<typename Container>
void PmergeMe<Container>::execute() {
  std::cout << "Before: ";
  for (const auto &value : _input) {
    std::cout << value << " ";
  }
  std::cout << '\n';

  auto pairs = makePairs();
  auto [largerElements, smallerElements] = extractElements(pairs);

  // Sort the larger elements recursively
  Container mainChain = sortLargerElements(pairs);

  // Now we must integrate the top-level smallerElements (if any)
  if (!smallerElements.empty()) {
    // Insert b_1
    ValueType b1 = smallerElements[0];
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), b1);
    mainChain.insert(it, b1);

    // Insert the rest of the b-elements using insertBElements
    if (smallerElements.size() > 1) {
      Container remainingB(smallerElements.begin() + 1, smallerElements.end());
      insertBElements(mainChain, remainingB, pairs);
    }
  }

  // Insert the straggler if it exists
  if (_hasStraggler) {
    auto it = std::lower_bound(mainChain.begin(), mainChain.end(), _straggler);
    mainChain.insert(it, _straggler);
  }

  std::cout << "After: ";
  for (const auto &value : mainChain) {
    std::cout << value << " ";
  }
  std::cout << '\n';
}


// Make Pairs
template <typename Container>
auto PmergeMe<Container>::makePairs() -> PairList {
  PairList pairs;
  size_t count = _hasStraggler ? _input.size() - 1 : _input.size();

  for (size_t i = 0; i < count; i += 2) {
    pairs.emplace_back(_input[i], _input[i + 1]);
  }

  normalizePairs(pairs);
  return pairs;
}

// Normalize Pairs
template <typename Container>
void PmergeMe<Container>::normalizePairs(PairList &pairs) {
  for (auto &pair : pairs) {
    if (pair.first < pair.second) {
      std::swap(pair.first, pair.second);
    }
  }
}

// Extract Elements
template <typename Container>
auto PmergeMe<Container>::extractElements(const PairList &pairs)
    -> std::pair<Container, Container> {
  Container largerElements;
  Container smallerElements;

  for (const auto &[first, second] : pairs) {
    largerElements.push_back(first);
    smallerElements.push_back(second);
  }

  return {std::move(largerElements), std::move(smallerElements)};
}

// Sort Larger Elements
template <typename Container>
Container PmergeMe<Container>::sortLargerElements(PairList &pairs) {
  // Base case
  if (pairs.size() <= 1) {
    Container sorted;
    for (const auto &[first, _] : pairs) {
      sorted.push_back(first);
    }
    return sorted;
  }

  // Recursive case
  Container largerElements;
  for (const auto &[first, _] : pairs) {
    largerElements.push_back(first);
  }

  bool hasLocalStraggler = (largerElements.size() % 2 != 0);
  ValueType localStraggler{};
  if (hasLocalStraggler) {
    localStraggler = largerElements.back();
    largerElements.pop_back();
  }

  PairList nextLevelPairs;
  for (size_t i = 0; i + 1 < largerElements.size(); i += 2) {
    if (largerElements[i] < largerElements[i + 1]) {
      std::swap(largerElements[i], largerElements[i + 1]); // use normalize pairs
    }
    nextLevelPairs.emplace_back(largerElements[i], largerElements[i + 1]);
  }

  auto [levelLargerElems, levelSmallerElems] = extractElements(nextLevelPairs);
  Container sortedChain = sortLargerElements(nextLevelPairs);

  if (hasLocalStraggler) {
    auto it = std::lower_bound(sortedChain.begin(), sortedChain.end(), localStraggler);
    sortedChain.insert(it, localStraggler);
  }

  // Insert b_1 from this recursion level, then the rest
  if (!levelSmallerElems.empty()) {
    ValueType b1 = levelSmallerElems[0];
    auto it = std::lower_bound(sortedChain.begin(), sortedChain.end(), b1);
    sortedChain.insert(it, b1);

    Container remainingB(levelSmallerElems.begin() + 1, levelSmallerElems.end());
    insertBElements(sortedChain, remainingB, pairs);
  }

  return sortedChain;
}

template <typename Container>
void PmergeMe<Container>::insertBElements(Container &mainChain, const Container &bElems, const PairList &pairs) {
  if (bElems.empty()) return;

  auto tSeq = generateTSequence(bElems.size());
  if (tSeq.empty()) return;

  size_t prev_t = 1;
  for (size_t i = 0; i < tSeq.size(); ++i) {
    size_t current_t = tSeq[i];
    // The block is [prev_t+1 ... current_t], insert in reverse order
    // Collect these b_i into a temporary block
    Container block;
    for (size_t idx = current_t; idx > prev_t; idx--) {
      if (idx >= 2) {
        size_t bIndex = idx - 2;
        if (bIndex < bElems.size()) {
          block.push_back(bElems[bIndex]);
        }
      }
    }

    if (!block.empty()) {
      // Find the pair where the second value matches the current value in block
      auto it = std::find_if(pairs.begin(), pairs.end(), [&block](const auto &pair) {
        return pair.second == block.front(); // Match the second value
      });

      if (it != pairs.end()) {
        const auto &highValue = it->first; // Take the first value (high) from the found pair
        binaryInsert(mainChain, block, highValue);
      }
    }

    prev_t = current_t;
  }

  // If any remain beyond last_t:
  size_t last_t = tSeq.back();
  Container leftover;
  for (size_t idx = bElems.size() + 1; idx > last_t; idx--) {
    if (idx >= 2 && (idx - 2) < bElems.size()) {
      leftover.push_back(bElems[idx - 2]);
    }
  }

  if (!leftover.empty()) {
    // Find the pair where the second value matches the current value in leftovers
    auto it = std::find_if(pairs.begin(), pairs.end(), [&leftover](const auto &pair) {
      return pair.second == leftover.front();
    });

    if (it != pairs.end()) {
      const auto &highValue = it->first; // Take the first value (high) from the found pair
      binaryInsert(mainChain, leftover, highValue);
    }
  }
}

template <typename Container>
void PmergeMe<Container>::binaryInsert(Container &mainChain,const Container &block,  const typename Container::value_type &highValue) {
  // Insert elements of block into mainChain using binary search for each element
  // block is already in reverse order of insertion (as required)

  for (const auto &val : block) {
    auto low = mainChain.begin();
    auto high = std::upper_bound(mainChain.begin(), mainChain.end(), highValue);

    while (low < high)
    {
      auto mid = low + distance(low, high) / 2;
      if(*mid < val) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    mainChain.insert(low, val);
  }
}


// Generate T Sequence (Jaochstall like seq, described in the book)
// t_k = (2^(k+1) + (-1)^k) / 3
// t_1=1, t_2=3, t_3=5, t_4=11, ...
template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateTSequence(size_t size) {
  std::vector<size_t> tSeq;
  if (size == 0) return tSeq;

  // We want to cover at least up to size+1 because b_2 corresponds to index 0
  // and b_(size+1) corresponds to smallerElements[size-1].
  // We'll generate t_k until t_k > size+1.
  // t_1=1 always:
  tSeq.push_back(1);
  size_t k = 2;
  while (true) {
    // Compute t_k:
    // 2^(k+1):
    size_t powVal = ((size_t)1 << (k+1));
    size_t numerator = powVal + ((k % 2 == 0) ? 1 : -1); // add +1 if even k, -1 if odd k
    size_t t_k = numerator / 3;

    if (t_k > size + 1) break;
    tSeq.push_back(t_k);
    k++;
  }

  return tSeq;
}