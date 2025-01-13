#pragma once

#include <exception>
#include <stdexcept>

template <typename T> class Array {
private:
  T *elements;         
  unsigned int len;

public:
  Array() : elements(nullptr), len(0) {}

  Array(unsigned int n) : elements(new T[n]()), len(n) {}

  Array(const Array<T> &other) : elements(nullptr), len(0) { *this = other; }

  Array<T> &operator=(const Array<T> &other) {
    if (this != &other) {
      delete[] elements;

      len = other.len;
      elements = new T[len];
      for (unsigned int i = 0; i < len; ++i) {
        elements[i] = other.elements[i];
      }
    }
    return *this;
  }

  ~Array() { delete[] elements; }

  T &operator[](unsigned int index) {
    if (index >= len) {
      throw std::out_of_range("Array index out of bounds");
    }
    return elements[index];
  }

  const T &operator[](unsigned int index) const {
    if (index >= len) {
      throw std::out_of_range("Array index out of bounds");
    }
    return elements[index];
  }

  unsigned int size() const { return len; }
};
