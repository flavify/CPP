#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv) {
    if (argc < 2) {
        throw std::invalid_argument("Error");
    }

    for (int i = 1; i < argc; ++i) {
        int num;
        try {
            num = std::stoi(argv[i]);
        } catch (...) {
            throw std::invalid_argument("Error");
        }
        if (num < 0) {
            throw std::invalid_argument("Error");
        }
        _input.push_back(num);
    }
}

template <typename Container>
void PmergeMe<Container>::execute() {
    // Print the unsorted sequence:
    std::cout << "Before: ";
    for (const auto &value : _input) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    // Step 1: Generate pairs
    PairList pairs = makePairs();
    // displayPairs(pairs);

    // Step 2: Extract larger and smaller elements
    auto [largerElements, smallerElements] = extractElements(pairs);

    // Step 3: Sort the larger elements recursively to form the main chain
    Container sortedMainChain = sortLargerElements(pairs);

    // Step 4: Merge smaller elements into the main chain using Jacobsthal sequence blocks
    binaryMerge(sortedMainChain, smallerElements);

    // Step 5: Handle the global straggler
    if (_hasStraggler) {
        auto it = std::lower_bound(sortedMainChain.begin(), sortedMainChain.end(), _straggler);
        sortedMainChain.insert(it, _straggler);
    }

    // Display the fully sorted sequence
    std::cout << "After: ";
    for (const auto &value : sortedMainChain) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
typename PmergeMe<Container>::PairList
PmergeMe<Container>::makePairs() {
    PairList pairs;

    for (size_t i = 0; i + 1 < _input.size(); i += 2) {
        pairs.push_back(PairType(_input[i], _input[i + 1]));
    }

    if (_input.size() % 2 != 0) {
        _straggler = _input.back();
    }

    _hasStraggler = (_input.size() % 2 != 0);

    normalizePairs(pairs);
    return pairs;
}

template <typename Container>
void PmergeMe<Container>::normalizePairs(PairList &pairs){
    for (auto &pair : pairs) {
        if (pair.first < pair.second) {
            std::swap(pair.first, pair.second);
        }
    }
}

template <typename Container>
std::pair<Container, Container>
PmergeMe<Container>::extractElements(const PairList &pairs) {
    Container largerElements;
    Container smallerElements;

    for (const auto &pair : pairs) {
        largerElements.push_back(pair.first);   // Larger element
        smallerElements.push_back(pair.second); // Smaller element
    }

    return std::make_pair(largerElements, smallerElements);
}

template <typename Container>
Container PmergeMe<Container>::sortLargerElements(PairList &pairs) {
    if (pairs.size() <= 1) {
        // Extract the larger element directly
        Container sortedLargerElements;
        for (const auto &pair : pairs) {
            sortedLargerElements.push_back(pair.first);
        }
        return sortedLargerElements;
    }

    // Extract larger elements for this recursion level
    Container largerElements;
    for (const auto &pair : pairs) {
        largerElements.push_back(pair.first);
    }

    // Handle local straggler
    PairList largerPairs;
    ValueType localStraggler = 0;
    bool hasLocalStraggler = (largerElements.size() % 2 != 0);
    if (hasLocalStraggler) {
        localStraggler = largerElements.back();
        largerElements.pop_back();
    }

    // Create next-level pairs
    for (size_t i = 0; i + 1 < largerElements.size(); i += 2) {
        ValueType first = largerElements[i];
        ValueType second = largerElements[i + 1];
        if (first < second) {
            std::swap(first, second);
        }
        largerPairs.push_back(PairType(first, second));
    }

    // Extract the smaller elements from these new pairs before recursion
    // This gives us the smaller elements at the current recursion level
    auto [levelLargerElems, levelSmallerElems] = extractElements(largerPairs);

    // Recursively sort the larger pairs (this returns a sorted chain of their larger elements)
    Container sortedLargerElements = sortLargerElements(largerPairs);

    // Insert the local straggler if present
    if (hasLocalStraggler) {
        auto it = std::lower_bound(sortedLargerElements.begin(), sortedLargerElements.end(), localStraggler);
        sortedLargerElements.insert(it, localStraggler);
    }

    // Now, we must re-insert the smaller elements from this recursion level
    // just like we do at the top level
    if (!levelSmallerElems.empty()) {
        binaryMerge(sortedLargerElements, levelSmallerElems);
    }

    return sortedLargerElements;
}


template <typename Container>
void PmergeMe<Container>::binaryMerge(Container &mainChain, const Container &smallerElements) {
    // Generate the Jacobsthal sequence
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(smallerElements.size());

    // Ensure we have a sentinel at the end to handle the last block of elements
    if (jacobsthal.empty() || jacobsthal.back() < smallerElements.size()) {
        jacobsthal.push_back(smallerElements.size());
    }

    // Insert elements in blocks determined by Jacobsthal indices
    for (size_t idx = 1; idx < jacobsthal.size(); ++idx) {
        size_t start = jacobsthal[idx-1];
        size_t end = jacobsthal[idx];

        // Insert elements from [start, end) in reverse order
        for (size_t i = end; i > start; --i) {
            size_t elemIndex = i - 1;
            if (elemIndex < smallerElements.size()) {
                auto it = std::lower_bound(mainChain.begin(), mainChain.end(), smallerElements[elemIndex]);
                mainChain.insert(it, smallerElements[elemIndex]);
            }
        }
    }
}

template <typename Container>
std::vector<size_t> PmergeMe<Container>::generateJacobsthalSequence(size_t size) {
    std::vector<size_t> jacobsthal;
    if (size == 0) return jacobsthal;

    jacobsthal.push_back(0); // J(0)
    if (size == 1) return jacobsthal;

    jacobsthal.push_back(1); // J(1)

    while (jacobsthal.back() < size) {
        size_t n = jacobsthal.size();
        size_t next = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
        if (next >= size) break;
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

template <typename Container>
void PmergeMe<Container>::displayPairs(const PairList &pairs) {
    std::cout << "Pairs: ";
    for (const auto &pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
    if (_hasStraggler == true) {
        std::cout << "Straggler: " << _straggler << std::endl;
    }
}
