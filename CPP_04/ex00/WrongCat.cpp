/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:59:45 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 00:59:49 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  _type = "WrongCat";
  std::cout << ORANGE << "WrongCat constructor called" 
            << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << ORANGE << "WrongCat copy constructor called" 
            << RESET << std::endl;
}

WrongCat WrongCat::operator=(const WrongCat &other) {
  if (this != &other)
    _type = other._type;
  std::cout << ORANGE << "WrongCat assignation operator called" 
            << RESET << std::endl;
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << ORANGE << "WrongCat destructor called" 
            << RESET << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << ORANGE << "* meow meow🐱 *" 
            << RESET << std::endl;
}