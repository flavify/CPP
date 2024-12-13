#include <vector>
#include <algorithm>
#include <optional>
#include <stdexcept>

class Span {
private:
  std::vector<int> numbers;
  unsigned int maxSize;

public:
  explicit Span(unsigned int n);
  void addNumber(int number);
  std::optional<int> shortestSpan() const;
  std::optional<int> longestSpan() const;
};