#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility> // for std::pair

template <typename Container>
class PmergeMe {
	public:
		typedef typename Container::value_type ValueType; // Type of the elements in the container
		typedef std::pair<ValueType, ValueType> PairType; // Pair of elements
		typedef std::vector<PairType> PairList; // List of pairs

		PmergeMe(int argc, char **argv);

		void execute();

	private:
		Container _input;
		ValueType _straggler;
		bool _hasStraggler;

		PairList makePairs();
		void normalizePairs(PairList &pairs);

		std::pair<Container, Container> extractElements(const PairList &pairs);
		Container sortLargerElements(PairList &pairs);

		void binaryMerge(Container &mainChain, const Container &smallerElements);

		std::vector<size_t> generateJacobsthalSequence(size_t size);

		void displayPairs(const PairList &pairs);
};

#include "PmergeMe.tpp"
