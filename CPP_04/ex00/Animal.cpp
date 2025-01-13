/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:10:50 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 19:59:41 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
  std::cout << GREEN << "Animal constructor called" 
            << RESET << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type){
  std::cout << GREEN << "Animal copy constructor called" 
            << RESET << std::endl;
}

Animal Animal::operator=(const Animal &other) {
  if (this != &other)
    _type = other._type;
  std::cout << GREEN << "Animal assignation operator called" 
            << RESET << std::endl;
  return *this;
}

Animal::~Animal() {
  std::cout << GREEN << "Animal destructor called" 
            << RESET << std::endl;
}

std::string Animal::getType() const {
  return _type;
}

void Animal::makeSound() const {
  std::cout << GREEN << "* random(not so random) animal sound🙊 *" 
            << RESET << std::endl;
}