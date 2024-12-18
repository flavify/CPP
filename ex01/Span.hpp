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
  Span(int n);
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span() = default;

  void addNumber(int number);
  template <typename InputIterator>
  void addNumbers(InputIterator begin, InputIterator end) {
    if (numbers.size() + std::distance(begin, end) > maxSize)
      throw std::overflow_error("Adding these numbers would exceed the Span's capacity.");
    numbers.insert(numbers.end(), begin, end);
  }

  int shortestSpan() const;
  int longestSpan() const;

  const std::vector<int>& getNumbers() const;
};
