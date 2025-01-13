#include "iter.hpp"
#include <iostream>

void printInt(int i) { std::cout << i << " "; }

void decrementInt(int &i) { i -= 1; }

void printString(const std::string &str) { std::cout << str << " "; }

int main() {
  int intArray[] = {1, 2, 3, 4, 5};
  std::size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Original integer array: ";
  iter(intArray, intLength, printInt);
  std::cout << std::endl;

  std::cout << "Decrementing each element in the integer array: ";
  iter(intArray, intLength, decrementInt);
  iter(intArray, intLength, printInt);
  std::cout << std::endl;

  std::string strArray[] = {"Hello", "what's", "upp", ",", "it s", "working"};
  std::size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

  std::cout << "Original string array: ";
  iter(strArray, strLength, printString);
  std::cout << std::endl;

  return 0;
}
