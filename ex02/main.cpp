#include "PmergeMe.hpp"


int main(int argc, char **argv) {
    try {
        std::cout << "Using std::vector:\n";
        PmergeMe<std::vector<int>> vectorSorter(argc, argv);
        vectorSorter.execute();

        std::cout << "\nUsing std::deque:\n";
        PmergeMe<std::deque<int>> dequeSorter(argc, argv);
        dequeSorter.execute();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
