#include "Span.hpp"

Span::Span(int n) {
  if (n <= 0) {
    throw std::invalid_argument("Span size must be greater than 0.");
  }
  maxSize = static_cast<unsigned int>(n);
}

Span::Span(const Span& other) {*this = other;}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    numbers = other.numbers;
    maxSize = other.maxSize;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (numbers.size() >= maxSize)
    throw std::overflow_error("Span is full, cannot add more numbers.");
  numbers.push_back(number);
}

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

int Span::longestSpan() const {
  if (numbers.size() < 2)
    throw std::logic_error("Not enough numbers to calculate the longest span.");
  
  auto [minIt, maxIt] = std::minmax_element(numbers.begin(), numbers.end());
  return *maxIt - *minIt;
}

const std::vector<int>& Span::getNumbers() const {
  return numbers;
}