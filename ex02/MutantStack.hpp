#pragma once

#include <stack>
#include <iterator>


template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // Typedefs for iterators
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

  /* Orthodox Canonical Form */
  MutantStack() = default;
  MutantStack(const MutantStack& other) = default;
  MutantStack& operator=(const MutantStack& other) = default;
  ~MutantStack() = default;

  // Iterator access
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"