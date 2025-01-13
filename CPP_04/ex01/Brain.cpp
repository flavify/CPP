/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:55:16 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 02:44:03 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Brain.hpp"

Brain::Brain() {
  for (int i = 0; i < 100; i++)
    _ideas[i] = "Not so smart ideea.";
  std::cout << GRAY << "Brain constructor called" 
            << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
  for (int i = 0; i < 100; i++)
    _ideas[i] = other.getIdea(i);
  std::cout << GRAY << "Brain copy constructor called" 
            << RESET << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
  if(this != &other) {
    for (int i = 0; i < 100; i++)
    _ideas[i] = other.getIdea(i);
  }
  std::cout << GRAY << "Brain assignation operator called" 
            << RESET << std::endl;
  return *this;
}

Brain::~Brain() {
  std::cout << GRAY << "Brain destructor called" 
            << RESET << std::endl;
}

std::string Brain::getIdea(int index) const {
  if (index < 0 || index >= 100) {
    throw std::out_of_range("Index out of range");
  }
  return _ideas[index];
}

void Brain::setIdea(int index, std::string& idea) {
    if (index < 0 || index >= 100) {
    throw std::out_of_range("Index out of range");
  }
  _ideas[index] = idea;
}