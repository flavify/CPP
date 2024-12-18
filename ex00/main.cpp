#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void printHeader(const std::string &title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

void printSuccess(int value) {
  std::cout << "✅ Found: " << value << std::endl;
}

void printError(const std::string &context, const std::string &error) {
  std::cerr << "❌ " << context << ": " << error << std::endl;
}

int main() {
  std::vector<int> vec = {10, 20, 30, 40, 50};
  std::list<int> lst = {1, 2, 3, 4, 5};

  printHeader("Vector Search");
  try {
    printSuccess(*easyfind(vec, 30));
    printSuccess(*easyfind(vec, 60));
  } catch (const std::exception &e) {
    printError("Vector Error", e.what());
  }

  printHeader("List Search");
  try {
    printSuccess(*easyfind(lst, 2));
    printSuccess(*easyfind(lst, 99));
  } catch (const std::exception &e) {
    printError("List Error", e.what());
  }

  return 0;
}