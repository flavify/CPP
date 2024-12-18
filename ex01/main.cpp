#include "Span.hpp"
#include <iostream>

int main() {
  try {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    std::vector<int> moreNumbers = {1, 2, 3};
    Span bigSpan(8);
    bigSpan.addNumbers(moreNumbers.begin(), moreNumbers.end());
    bigSpan.addNumber(10);
    bigSpan.addNumber(20);

    std::cout << "Shortest Span (Big Span): " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span (Big Span): " << bigSpan.longestSpan() << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
