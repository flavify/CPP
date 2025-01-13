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

  if (_hasStraggler) {
    binaryInsert(mainChain, _straggler, *(mainChain.end() - 1));
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
    for (const auto &[first, second] : pairs) {
      sorted.push_back(second);
      if (pairs.size() == 1) {
        sorted.push_back(first);
      }
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
      std::swap(largerElements[i], largerElements[i + 1]);
    }
    nextLevelPairs.emplace_back(largerElements[i], largerElements[i + 1]);
  }

  auto [levelLargerElems, levelSmallerElems] = extractElements(nextLevelPairs);
  Container sortedChain = sortLargerElements(nextLevelPairs);

  if (hasLocalStraggler) {
    binaryInsert(sortedChain, localStraggler, *(sortedChain.end() - 1));
  }

  // Insert b_1 from this recursion level, then the rest
  if (!levelSmallerElems.empty()) {
    insertBElements(sortedChain, pairs);
  }

  return sortedChain;
}

template <typename Container>
void PmergeMe<Container>::insertBElements(Container &mainChain, const PairList &pairs) {
  if (pairs.empty()) return;

  auto tSeq = generateTSequence(pairs.size());
  if (tSeq.empty()) return;

  size_t prev_t = 1;
  for (size_t i = 0; i < tSeq.size(); ++i) {
    size_t current_t = tSeq[i];
    // The block is [prev_t+1 ... current_t], insert in reverse order
    // Collect these b_i into a temporary block
    PairList block;
    for (size_t idx = current_t; idx > prev_t; idx--) {
      if (idx >= 2) {
        size_t bIndex = idx - 2;
        if (bIndex < pairs.size()) {
          block.push_back(pairs[bIndex]);
        }
      }
    }

    if (!block.empty()) {
      for (const auto &pair : block)
        binaryInsert(mainChain, pair.second, pair.first);
    }

    prev_t = current_t;
  }
  
  size_t last_t = tSeq.back();
  PairList leftover;
  for (size_t idx = pairs.size() + 1; idx > last_t; idx--) {
    if (idx >= 2 && (idx - 2) < pairs.size()) {
      leftover.push_back(pairs[idx - 2]);
    }
  }

  if (!leftover.empty()) {
    for (const auto &pair : leftover)
      binaryInsert(mainChain, pair.second, pair.first);
  }
}

template <typename Container>
void PmergeMe<Container>::binaryInsert(Container &mainChain, 
        const typename Container::value_type &lowValue,  const typename Container::value_type &highValue) {
  auto low = mainChain.begin();
  auto high = std::upper_bound(mainChain.begin(), mainChain.end(), highValue);

  while (low < high)
  {
    auto mid = low + distance(low, high) / 2;
    if(*mid < lowValue) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  mainChain.insert(low, lowValue);
}


// Generate T Sequence (Jaochstall like seq, described in the book)
// t_k = (2^(k+1) + (-1)^k) / 3
// t_1=1, t_2=3, t_3=5, t_4=11, ...
template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateTSequence(size_t size) {
  std::vector<size_t> tSeq;
  if (size == 0) return tSeq;

  tSeq.push_back(1);
  size_t k = 2;
  while (true) {
    size_t powVal = ((size_t)1 << (k+1));
    size_t numerator = powVal + ((k % 2 == 0) ? 1 : -1);
    size_t t_k = numerator / 3;

    if (t_k > size + 1) break;
    tSeq.push_back(t_k);
    k++;
  }

  return tSeq;
}