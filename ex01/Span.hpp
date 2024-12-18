#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
 private:
  std::vector<int> numbers;
  unsigned int maxSize;

 public:
  explicit Span(unsigned int n);
  void addNumber(int number);

  template <typename InputIterator>
  void addNumbers(InputIterator begin, InputIterator end);
  int shortestSpan() const;
  int longestSpan() const;
};
