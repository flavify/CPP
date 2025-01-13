#include "Array.hpp"
#include <iostream>
#include <string>
#include <sstream>

#define RESET        "\033[0m"
#define GREEN        "\033[1;32m"
#define RED          "\033[1;31m"
#define BLUE         "\033[1;34m"
#define YELLOW       "\033[1;33m"
#define CYAN         "\033[1;36m"

static const size_t BOX_WIDTH_INT = 39; 
static const size_t BOX_WIDTH_STR = 50; 

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
  std::stringstream ss;
  ss << "| " << name << ": ";
  for (unsigned int i = 0; i < arr.size(); ++i) {
    ss << arr[i] << " ";
  }

  std::string line = ss.str();
  size_t current_len = line.size();

  if (current_len + 1 < BOX_WIDTH_INT) {
    line.append(BOX_WIDTH_INT - current_len - 1, ' ');
  }
  line.push_back('|');

  std::cout << CYAN << "+-------------------------------------+" << RESET << std::endl;
  std::cout << CYAN << line << RESET << std::endl;
  std::cout << CYAN << "+-------------------------------------+" << RESET << std::endl << std::endl;
}

// Specialization for std::string to include quotes
template <>
void printArray<std::string>(const Array<std::string>& arr, const std::string& name) {
  std::stringstream ss;
  ss << "| " << name << ": ";
  for (unsigned int i = 0; i < arr.size(); ++i) {
    ss << "\"" << arr[i] << "\" ";
  }

  std::string line = ss.str();
  size_t current_len = line.size();
  if (current_len + 1 < BOX_WIDTH_STR) {
    line.append(BOX_WIDTH_STR - current_len - 1, ' ');
  }
  line.push_back('|');

  std::cout << CYAN << "+------------------------------------------------+" << RESET << std::endl;
  std::cout << CYAN << line << RESET << std::endl;
  std::cout << CYAN << "+------------------------------------------------+" << RESET << std::endl << std::endl;
}

int main() {
  try {
    std::cout << BLUE << "\n-- Testing with int array --" << RESET << std::endl;

    Array<int> emptyArray;
    std::cout << YELLOW << "Empty int array size:" << RESET << " " << emptyArray.size() << std::endl;

    Array<int> intArray(5);
    std::cout << YELLOW << "Int array with 5 elements, default initialized:" << RESET << std::endl;
    printArray(intArray, "intArray (default)");

    for (unsigned int i = 0; i < intArray.size(); ++i) {
      intArray[i] = i * 2;
    }
    std::cout << YELLOW << "Modified int array:" << RESET << std::endl;
    printArray(intArray, "intArray (modified)");

    Array<int> copiedIntArray(intArray);
    std::cout << YELLOW << "Copied int array:" << RESET << std::endl;
    printArray(copiedIntArray, "copiedIntArray");

    Array<int> assignedIntArray = intArray;
    std::cout << YELLOW << "Assigned int array:" << RESET << std::endl;
    printArray(assignedIntArray, "assignedIntArray");

    std::cout << YELLOW << "Attempting out-of-bounds access for int array..." << RESET << std::endl;
    std::cout << intArray[10] << std::endl;  // Should throw

  } catch (const std::exception &e) {
    std::cerr << RED << "Exception caught (int test):" << RESET << " " << e.what() << std::endl;
  }

  try {
    std::cout << BLUE << "\n-- Testing with std::string array --" << RESET << std::endl;

    Array<std::string> emptyStrArray;
    std::cout << YELLOW << "Empty string array size:" << RESET << " " << emptyStrArray.size() << std::endl;

    Array<std::string> strArray(3);
    std::cout << YELLOW << "String array with 3 elements, default initialized:" << RESET << std::endl;
    printArray(strArray, "strArray (default)");

    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    std::cout << YELLOW << "Modified string array:" << RESET << std::endl;
    printArray(strArray, "strArray (modified)");

    Array<std::string> copiedStrArray(strArray);
    std::cout << YELLOW << "Copied string array:" << RESET << std::endl;
    printArray(copiedStrArray, "copiedStrArray");

    Array<std::string> assignedStrArray = strArray;
    assignedStrArray[1] = "There"; // Ensure deep copy
    std::cout << YELLOW << "Assigned string array (modified):" << RESET << std::endl;
    printArray(assignedStrArray, "assignedStrArray");

    std::cout << YELLOW << "Original string array after assigned array modified:" << RESET << std::endl;
    printArray(strArray, "strArray (original)");

    std::cout << YELLOW << "Attempting out-of-bounds access for string array..." << RESET << std::endl;
    std::cout << strArray[5] << std::endl; // Should throw

  } catch (const std::exception &e) {
    std::cerr << RED << "Exception caught (string test):" << RESET << " " << e.what() << std::endl;
  }

  return 0;
}
