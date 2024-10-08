#pragma once

template <typename T> class Array {
private:
  T *elements; // point to dynamically alocated array
  int len;

public:
  Array() : elements(nullptr), len(0) {}

  Array(int n) : elements(new T[n]()), len(n) {}

  Array(const Array<T> &other) : elements(nullptr), len(0) { *this = other; }

  Array<T> &operator=(const Array<T> &other) {
    if (this != &other) {
      delete[] elements; // Free the old memory

      length = other.length;
      elements = new T[length];
      for (unsigned int i = 0; i < length; ++i) {
        elements[i] = other.elements[i]; // Deep copy each element
      }
    }
    return *this;
  }

  ~Array() { delete[] elements };
	
};