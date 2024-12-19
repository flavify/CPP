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
    binaryMerge(mainChain, smallerElements);
  }
}

// Binary Merge
template <typename Container>
void PmergeMe<Container>::binaryMerge(Container &mainChain, const Container &smallerElements) {
  auto jacobsthal = generateJacobsthalSequence(smallerElements.size());

  if (jacobsthal.empty() || jacobsthal.back() < smallerElements.size()) {
    jacobsthal.push_back(smallerElements.size());
  }

  for (size_t idx = 1; idx < jacobsthal.size(); ++idx) {
    size_t start = jacobsthal[idx - 1];
    size_t end = jacobsthal[idx];

    for (size_t i = end; i > start; --i) {
      auto elemIndex = i - 1;
      if (elemIndex < smallerElements.size()) {
        auto it = std::lower_bound(mainChain.begin(), mainChain.end(),
                                   smallerElements[elemIndex]);
        mainChain.insert(it, smallerElements[elemIndex]);
      }
    }
  }
}

// Generate Jacobsthal Sequence
template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateJacobsthalSequence(size_t size) {
  std::vector<size_t> jacobsthal;
  if (size == 0) return jacobsthal;

  jacobsthal.push_back(0);
  if (size == 1) return jacobsthal;

  jacobsthal.push_back(1);
  while (jacobsthal.back() < size) {
    size_t n = jacobsthal.size();
    size_t next = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
    if (next >= size) break;
    jacobsthal.push_back(next);
  }

  return jacobsthal;
}
