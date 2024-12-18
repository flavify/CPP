#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testMutantStack() {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << "MutantStack - Top: " << mstack.top() << std::endl;
  mstack.pop();

  std::cout << "MutantStack - Size: " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  std::cout << "MutantStack - Iterating through stack:" << std::endl;
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::stack<int> s(mstack);  // Copy to standard stack
  std::cout << "MutantStack - Copied stack size: " << s.size() << std::endl;
}

void testList() {
  std::list<int> lst;

  lst.push_back(5);
  lst.push_back(17);

  std::cout << "List - Top: " << lst.back() << std::endl;
  lst.pop_back();

  std::cout << "List - Size: " << lst.size() << std::endl;

  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);

  std::cout << "List - Iterating through list:" << std::endl;
  std::list<int>::iterator it = lst.begin();
  std::list<int>::iterator ite = lst.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::list<int> s(lst);
  std::cout << "List - Copied list size: " << s.size() << std::endl;
}

int main() {
  std::cout << "Testing MutantStack:" << std::endl;
  testMutantStack();

  std::cout << "\nTesting List" << std::endl;
  testList();

  return 0;
}
