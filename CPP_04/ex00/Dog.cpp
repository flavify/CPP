/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:44:27 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 19:59:57 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
  _type = "Dog";
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
  std::cout << BLUE << "Dog destructor called" 
            << RESET << std::endl;
}

void Dog::makeSound() const {
  std::cout << BLUE << "* barks🐶 *" 
            << RESET << std::endl;
}