#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdexcept>

template <typename Container>
class PmergeMe {
	public:
		using ValueType = typename Container::value_type;
		using PairType = std::pair<ValueType, ValueType>;
		using PairList = std::vector<PairType>;

		PmergeMe() = default;
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other) = default;
		PmergeMe &operator=(const PmergeMe &other) = default;
		~PmergeMe() = default;

		void execute();

	private:
		Container _input;
		ValueType _straggler;
		bool _hasStraggler = false;

		PairList makePairs();
		void normalizePairs(PairList &pairs);
		Container sortLargerElements(PairList &pairs);

		std::pair<Container, Container> extractElements(const PairList &pairs);
		void insertBElements(Container &mainChain, const PairList &pairs);
		void binaryInsert(Container &mainChain, const typename Container::value_type &lowValue,  const typename Container::value_type &highValue);


		std::vector<size_t> generateTSequence(size_t size);
};

#include "PmergeMe.tpp"

