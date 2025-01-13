/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:44:27 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 02:53:00 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal() {
  _type = "Dog";
  this->_brain = new Brain();
  std::cout << BLUE << "Dog constructor called" 
            << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << BLUE << "Dog copy constructor called" 
            << RESET << std::endl;
}

Dog Dog::operator=(const Dog &other) {
  if (this != &other)
    _type = other._type;
  std::cout << BLUE << "Dog assignation operator called" 
            << RESET << std::endl;
  return *this;
}

Dog::~Dog() {
  delete _brain;
  std::cout << BLUE << "Dog destructor called" 
            << RESET << std::endl;
}

void Dog::makeSound() const {
  std::cout << BLUE << "* bark bark🐶 *" 
            << RESET << std::endl;
}
