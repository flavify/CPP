#pragma once

/*Function template to swap 2 values*/
template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

/*Function template to return the minimum of 2 values*/
template <typename T> T min(const T &a, const T &b) { return (a < b) ? a : b; }

/*Function template to return the maximum of 2 values*/
template <typename T> T max(const T &a, const T &b) { return (a > b) ? a : b; }