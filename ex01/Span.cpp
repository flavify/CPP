#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

void Span::addNumber(int number) {
  if (numbers.size() >= maxSize) {
    throw std::runtime_error("Span is full");
  }
  numbers.push_back(number);
}

std::optional<int> Span::shortestSpan() const {
  if (numbers.size() < 2) {
    return std::nullopt;
  }
  std::vector<int> sorted = numbers;
  std::sort(sorted.begin(), sorted.end());
  int shortest = sorted[1] - sorted[0];
  for (size_t i = 1; i < sorted.size() - 1; ++i) {
    shortest = std::min(shortest, sorted[i + 1] - sorted[i]);
  }
  return shortest;
}

std::optional<int> Span::longestSpan() const {
  if (numbers.size() < 2) {
    return std::nullopt;
  }
  auto [minIt, maxIt] = std::minmax_element(numbers.begin(), numbers.end());
  return *maxIt - *minIt;
}