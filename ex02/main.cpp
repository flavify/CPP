#include "Array.hpp"
#include <iostream>

int main() {
  try {
    /* Test default constructor (empty array) */
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    /* Test constructor with size parameter */
    Array<int> intArray(5);
    std::cout << "Array with 5 elements, default initialized: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    /* Modify the array elements */
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      intArray[i] = i * 2;
    }
    std::cout << "Modified array: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    /* Test copy constructor */
    Array<int> copiedArray(intArray);
    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
      std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    /* Test assignment operator */
    Array<int> assignedArray = intArray;
    std::cout << "Assigned array: ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
      std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    /* Test out-of-bounds access */
    std::cout << "Attempting out-of-bounds access..." << std::endl;
    std::cout << intArray[10] << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
