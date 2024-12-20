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

// Execute
template <typename Container>
void PmergeMe<Container>::execute() {
  std::cout << "Before: ";
  for (const auto &value : _input) {
    std::cout << value << " ";
  }
  std::cout << '\n';

  auto pairs = makePairs();
  auto [largerElements, smallerElements] = extractElements(pairs);
  auto mainChain = sortLargerElements(pairs);

  mergeWithSmallerElements(mainChain, smallerElements);

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
  if (pairs.size() <= 1) {
    Container sorted;
    for (const auto &[first, _] : pairs) {
      sorted.push_back(first);
    }
    return sorted;
  }

  Container largerElements;
  for (const auto &[first, _] : pairs) {
    largerElements.push_back(first);
  }

  bool hasLocalStraggler = largerElements.size() % 2 != 0;
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
  auto sortedChain = sortLargerElements(nextLevelPairs);

  if (hasLocalStraggler) {
    auto it = std::lower_bound(sortedChain.begin(), sortedChain.end(), localStraggler);
    sortedChain.insert(it, localStraggler);
  }

  mergeWithSmallerElements(sortedChain, levelSmallerElems);
  return sortedChain;
}

// Merge with Smaller Elements
template <typename Container>
void PmergeMe<Container>::mergeWithSmallerElements(Container &mainChain,
                                                   const Container &smallerElements) {
  if (!smallerElements.empty()) {
    binaryInsert(mainChain, smallerElements);
  }
}

// Binary insertion using T sequence
template <typename Container>
void PmergeMe<Container>::binaryInsert(Container &mainChain, const Container &smallerElements) {
  // smallerElements: [b2, b3, b4, b5, ...] => smallerElements[0] = b2
  // According to FJ algorithm:
  // Blocks between t_k and t_{k+1}:
  // Insert block [t_k+1 ... t_{k+1}] in reverse order of b_i
  auto tSeq = generateTSequence(smallerElements.size());
  
  // If no tSeq, means no insertions needed
  if (tSeq.empty()) {
    return;
  }

  size_t prev_t = 1; // We consider t_0 = 1 for convenience
  for (size_t i = 0; i < tSeq.size(); ++i) {
    size_t current_t = tSeq[i];
    // Block is from prev_t+1 to current_t
    // Insert in reverse order
    for (size_t idx = current_t; idx > prev_t; idx--) {
      // idx corresponds to b_idx
      // b2 = smallerElements[0] => general formula: b_i maps to smallerElements[i-2]
      if (idx >= 2) {
        size_t bIndex = idx - 2;
        if (bIndex < smallerElements.size()) {
          const ValueType &val = smallerElements[bIndex];
          auto it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
          mainChain.insert(it, val);
        }
      }
    }
    prev_t = current_t;
  }

  // If there are still elements in smallerElements not covered by the last t_k:
  // Insert them as well, following the pattern
  // But by construction, t_k should cover all elements up to some point
  size_t last_t = tSeq.back();
  // If last_t < size+1, we might still have elements: b_(last_t+1), b_(last_t+2), ...
  for (size_t idx = smallerElements.size() + 1; idx > last_t; idx--) {
    // Insert any leftover
    if (idx >= 2 && (idx - 2) < smallerElements.size()) {
      size_t bIndex = idx - 2;
      const ValueType &val = smallerElements[bIndex];
      auto it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
      mainChain.insert(it, val);
    }
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