#include "PmergeMe.hpp"
#include <chrono>
#include <deque>

int main(int argc, char **argv) {
  try {
  	// Measure time using std::vector
    auto start_vector = std::chrono::high_resolution_clock::now();
    PmergeMe<std::vector<int>> sorter_vector(argc, argv);
    sorter_vector.execute();
    auto end_vector = std::chrono::high_resolution_clock::now();
    double time_vector = std::chrono::duration<double, std::micro>(end_vector - start_vector).count();

    auto start_deque = std::chrono::high_resolution_clock::now();
    PmergeMe<std::deque<int>> sorter_deque(argc, argv);
    sorter_deque.execute();
    auto end_deque = std::chrono::high_resolution_clock::now();
    double time_deque = std::chrono::duration<double, std::micro>(end_deque - start_deque).count();

    // The input size is argc-1 because we start from index 1 to read the numbers
    size_t input_size = static_cast<size_t>(argc - 1);

    // Print timing results
    std::cout << "Time to process a range of " << input_size << " elements with std::vector : " 
          	  << time_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << input_size << " elements with std::deque : " 
              << time_deque << " us" << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error" << std::endl;
    return 1;
	}

  return 0;
}
