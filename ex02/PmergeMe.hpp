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

		PmergeMe(int argc, char **argv);

		void execute();

	private:
		Container _input;
		ValueType _straggler;
		bool 			_hasStraggler = false;

		PairList makePairs();
		void normalizePairs(PairList &pairs);
		Container sortLargerElements(PairList &pairs);

		std::pair<Container, Container> extractElements(const PairList &pairs);
		void binaryMerge(Container &mainChain, const Container &smallerElements);
		std::vector<size_t> generateJacobsthalSequence(size_t size);
};

#include "PmergeMe.tpp"
