/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:02:09 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/14 17:55:44 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

/**
 * @brief Default Constructor.
 * 
 * Initializes the fixed-point nubmer to zero.
 * Prints a message indicating the default constructor
 * is called.
*/
Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Copy constructor.
 * 
 * Initializes the fixed-point number with the value of
 * another Fixed object.
 * Prints a message indicating the copy constuctor is called.
 * 
 * @param other The Fixed object to copy from.
*/
Fixed::Fixed(const Fixed& other) : _value(other._value) {
  std::cout << "Copy constructor called" << std::endl;
}

/**
 * @brief Copy assignment operator.
 * 
 * It assigns the value of another Fixed object to this one.
 * Prints a message indicating the copy asignment operator
 * is called.
 * 
 * @param other The Fixed object to get the value from.
 * @return A reference to this Fixed object.
*/
Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other.getRawBits();
  }
  return *this;
}

/**
 * @brief Destructor.
 * 
 * Releases all the allocated resources.
 * Prints a message indicating the destructor is called.
*/
Fixed::~Fixed() {
  std::cout << "Destructor called" <<std::endl;
}

/**
 * @brief Gets the raw bit representation of the fixed-point nbr.
 * 
 * Prints a message indicating this function is called.
 * 
 * @return The raw bits repersentation of the fixed-point nbr.
*/
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" \
            << std::endl;
  return _value;
}

/**
 * @brief Sets the raw bit representaton of the fixed-point nbr.
 * 
 * Prints a message indicating this function is called.
 * 
 * @param raw The raw bits to set.
*/
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" \
          << std::endl;
  _value = raw;
}

/**
 * @brief Prints the output value.
 *
 * A utility function to print the current value of the
 * fixed-point number and the number of fractional bits.
*/
void Fixed::printOutput() {
  std::cout << _value << std::endl;
  std::cout << _frBits << std::endl;
}
