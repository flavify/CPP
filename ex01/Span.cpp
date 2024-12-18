#include "Span.hpp"

// Constructor
Span::Span(unsigned int n) : maxSize(n) {}

// Add a single number
void Span::addNumber(int number) {
  if (numbers.size() >= maxSize)
    throw std::overflow_error("Span is full, cannot add more numbers.");
  numbers.push_back(number);
}

// Calculate the shortest span
int Span::shortestSpan() const {
  if (numbers.size() < 2)
    throw std::logic_error("Not enough numbers to calculate the shortest span.");
  
  std::vector<int> sorted = numbers;
  std::sort(sorted.begin(), sorted.end());

  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    int diff = sorted[i] - sorted[i - 1];
    minSpan = std::min(minSpan, diff);
  }
  return minSpan;
}

// Calculate the longest span
int Span::longestSpan() const {
  if (numbers.size() < 2)
    throw std::logic_error("Not enough numbers to calculate the longest span.");
  
  auto [minIt, maxIt] = std::minmax_element(numbers.begin(), numbers.end());
  return *maxIt - *minIt;
}
