#include "Span.hpp"
#include <iostream>
#include <vector>
#include <deque>

#define RESET   "\033[0m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"

void printHeader(const std::string& title) {
  std::cout << "\n" << BLUE
            << "========== " << title << " =========="
            << RESET << std::endl;
}

void printNumbers(const std::vector<int>& numbers) {
  std::cout << CYAN << "Numbers in Span: [ ";
  for (size_t i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i];
    if (i != numbers.size() - 1) std::cout << ", ";
  }
  std::cout << " ]" << RESET << std::endl;
}

void printSpanResults(const Span& span) {
  printNumbers(span.getNumbers());
  try {
    std::cout << "  Shortest Span: " << GREEN << span.shortestSpan() << RESET << std::endl;
    std::cout << "  Longest Span: " << YELLOW << span.longestSpan() << RESET << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "  " << RED << "Error: " << e.what() << RESET << std::endl;
  }
}

int main() {
  try {
    printHeader("Testing Small Capacity Span");
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    printSpanResults(sp);

    printHeader("Testing Larger Capacity Span");
    std::vector<int> moreNumbers = {1, 2, 3};
    Span bigSpan(8);
    bigSpan.addNumbers(moreNumbers.begin(), moreNumbers.end());
    bigSpan.addNumber(10);
    bigSpan.addNumber(20);
    bigSpan.addNumber(40);
    bigSpan.addNumber(50);
    bigSpan.addNumber(60);
    printSpanResults(bigSpan);

    // printHeader("Testing with 10000 Numbers");
    // Span humongousSpan(10000);
    // std::deque<int> d(10000);
    // for (int i = 0; i < int(d.size()); ++i)
    //     d[i] = rand() % 100;
    // humongousSpan.addNumbers(d.begin(), d.end());
    // printSpanResults(humongousSpan);

    std::cout << "\nAdding another number to exceed capacity...\n";
    bigSpan.addNumber(33);

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  return 0;
}


