#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv) {
    if (argc < 2) {
        throw std::invalid_argument("Error: At least one argument is required.");
    }

    for (int i = 1; i < argc; ++i) {
        int num = std::stoi(argv[i]);
        if (num < 0) {
            throw std::invalid_argument("Error: Only positive integers are allowed.");
        }
        _input.push_back(num);
    }
}


template <typename Container>
void PmergeMe<Container>::execute() {
    std::cout << "Input: ";
    for (const auto &value : _input) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    PairList pairs = makePairs();
    displayPairs(pairs);
}

template <typename Container>
typename PmergeMe<Container>::PairList
PmergeMe<Container>::makePairs() const {
	PairList pairs;

	for (size_t i = 0; i + 1 < _input.size(); i += 2) {
		pairs.push_back(PairType(_input[i], _input[i + 1]));
	}

    // Handle odd-sized container (last element paired with itself)
	if (_input.size() % 2 != 0) {
        pairs.push_back(PairType(_input.back(), _input.back())); 
    }

    return pairs;
}

template <typename Container>
void PmergeMe<Container>::displayPairs(const PairList &pairs) const {
    std::cout << "Pairs: ";
    for (const auto &pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
}
