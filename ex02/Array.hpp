#pragma once

template <typename T> class Array {
private:
  T *elements;
  int len;

public:
  Array() : elements(nullptr), len(0) {}

  Array(int n) : elements(new T[n]()), len(n) {}

  Array(const Array<T> &other) : elements(nullptr), len(0) { *this = other; }

  Array<T> &operator=(const Array<T> &other) {
    if (this != &other) {
      delete[] elements;

      length = other.length;
      elements = new T[length];
      for (unsigned int i = 0; i < length; ++i) {
        elements[i] = other.elements[i];
      }
    }
    return *this;
  }

  ~Array() { delete[] elements };

  T &operator[](int idx) {
    if (idx >= len) {
      throw std::out_of_range("Array index out of bounds");
    }
    return elements[idx];
  }

  const T &operator[](unsigned int index) const {
    if (index >= length) {
      throw std::out_of_range("Array index out of bounds");
    }
    return elements[index];
  }

  int size() const { return len; }
};