/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:51:10 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 00:54:39 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << PURPLE << "WrongAnimal constructor called" 
            << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type){
  std::cout << PURPLE << "WrongAnimal copy constructor called" 
            << RESET << std::endl;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other)
    _type = other._type;
  std::cout << PURPLE << "WrongAnimal assignation operator called" 
            << RESET << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << PURPLE << "WrongAnimal destructor called" 
            << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
  return _type;
}

void WrongAnimal::makeSound() const {
  std::cout << PURPLE << "* wrong animal sound🙊 *" 
            << RESET << std::endl;
}