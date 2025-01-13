/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:26:09 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/14 20:20:21 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

/**
 * @brief Default Constructor.
 * 
 * Initializes the fixed-point nubmer to zero.
*/
Fixed::Fixed() : _value(0) {
  // std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Constructor that takes an integer.
 * 
 * Converts the given integer to the corresponding fixed-point
 * value.
 * The frBits value is 8.
 * 
 * @param number The integer to convert into a fixed-point 
 * value.
*/
Fixed::Fixed(const int number) {
  // std::cout << "Int constructor called" << std::endl;
  _value = number << _frBits;
}

/**
 * @brief Constructor that takes an float.
 * 
 * Converts the given float to the corresponding fixed-point
 * value.
 * The frBits value is 8.
 * 
 * @param number The float to convert into a fixed-point 
 * value.
*/
Fixed::Fixed(float number) {
  // std::cout << "Float constructor called" << std::endl;
  _value = roundf(number * (1 << _frBits));
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
  // std::cout << "Copy constructor called" << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Releases all the allocated resources.
 * Prints a message indicating the destructor is called.
*/
Fixed::~Fixed() {
  // std::cout << "Destructor called" <<std::endl;
}

/*Assignment operator*/
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
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other.getRawBits();
  }
  return *this;
}

/*Comparison operators*/
/**
 * @brief Greater-than operator.
 * 
 * Comapres the value of this Fixed object with another.
 * 
 * @param other The Fixed object to compare to.
 * @return True if this object is greater than the other,
 * false otherwise.
*/
bool Fixed::operator>(const Fixed& other) const {
  return this->_value > other._value;
}

/**
 * @brief Lesser-than operator.
 * 
 * Comapres the value of this Fixed object with another.
 * 
 * @param other The Fixed object to compare to.
 * @return True if this object is lesser than the other,
 * false otherwise.
*/
bool Fixed::operator<(const Fixed& other) const {
  return this->_value < other._value;
}

/**
 * @brief Greater-than-or-equal-to operator.
 *  
 * Compares the value of this Fixed object with another.
 * 
 * @param other The Fixed object to compare with.
 * @return True if this object is greater than or equal to the other, 
 * false otherwise.
 */
bool Fixed::operator>=(const Fixed& other) const {
  return this->_value >= other._value;
}

/**
 * @brief Lesser-than-or-equal-to operator.
 *  
 * Compares the value of this Fixed object with another.
 * 
 * @param other The Fixed object to compare with.
 * @return True if this object is lesser than or equal to the other, 
 * false otherwise.
 */
bool Fixed::operator<=(const Fixed& other) const {
  return this->_value <= other._value;
}

/**
 * @brief Equality operator.
 *
 * Compares the value of this Fixed object with another.
 * 
 * @param other The Fixed object to compare with.
 * @return True if the objects have the same value,
 * false otherwise.
*/
bool Fixed::operator==(const Fixed& other) const {
  return this->_value == other._value;
}

/**
 * @brief Inequality operator.
 *
 * Compares the value of this Fixed object with another.
 * 
 * @param other The Fixed object to compare with.
 * @return True if the objects have different values,
 * false otherwise.
*/
bool Fixed::operator!=(const Fixed& other) const {
  return this->_value != other._value;
}

/*Arithmetic operators*/

/**
 * @brief Addition operator.
 * Adds the value of another Fixed object to this one.
 * 
 * @param other The Fixed object to add.
 * @return A new Fixed object containing the result of
 * the addition.
*/
Fixed Fixed::operator+(const Fixed& other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

/**
 * @brief Substraction operator.
 * Substracts the value of another Fixed object to this one.
 * 
 * @param other The Fixed object to substracts.
 * @return A new Fixed object containing the result of
 * the substraction.
*/
Fixed Fixed::operator-(const Fixed& other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

/**
 * @brief Multiplication operator.
 * Multiplies the value of another Fixed object with this one.
 * 
 * @param other The Fixed object to multiply.
 * @return A new Fixed object containing the result of
 * the multiplication.
*/
Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

/**
 * @brief Division operator.
 * Divides the value of this operator by another.
 * 
 * @param other The Fixed object to divide by.
 * @return A new Fixed object contining the result of
 * the division.
*/
Fixed Fixed::operator/(const Fixed& other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

/*Increment/Decrement Operators*/

/**
 * @brief Pre-increment operator.
 * 
 * Increments the value of this FIxed object by one.
 * 
 * @return A reference to this Fixed object after 
 * incrementing.
*/
Fixed& Fixed::operator++() {
    this->_value++;
    return *this;
}

/**
 * @brief Post-increment operator.
 * 
 * Increments the value of this Fixed object by one.
 * 
 * @return A new Fixed object containing the value 
 * before incrementing.
 */
Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  this->_value++;
  return tmp;
}

/**
 * @brief Pre-decremet operator.
 * 
 * Decrements the value of this FIxed object by one.
 * 
 * @return A reference to this Fixed object after 
 * decrementig.
*/
Fixed& Fixed::operator--() {
    this->_value--;
    return *this;
}

/**
 * @brief Post-decrement operator.
 * 
 * Decrements the value of this Fixed object by one.
 * 
 * @return A new Fixed object containing the value 
 * before decrementing.
 */
Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  this->_value++;
  return tmp;
}

/*Overloaded methods*/
/**
 * @brief Returns the minimum of two Fixed objects.
 * 
 * @param a The first Fixed object.
 * @param b The second Fixed object.
 * @return A reference to the Fixed object with the 
 * smaller value.
*/
const Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return a < b ? a : b;
}

/**
 * @brief Returns the minimum of two constant
 *  Fixed objects.
 * 
 * @param a The first Fixed object.
 * @param b The second Fixed object.
 * @return A reference to the Fixed object with the 
 * smaller value.
*/
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return a < b ? a : b;
}

/**
 * @brief Returns the maximum of two Fixed objects.
 * 
 * @param a The first Fixed object.
 * @param b The second Fixed object.
 * @return A reference to the Fixed object with the 
 * larger value.
*/
const Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return b > a ? b : a;
}

/**
 * @brief Returns the maximum of two constant 
 * Fixed objects.
 * 
 * @param a The first Fixed object.
 * @param b The second Fixed object.
 * @return A reference to the Fixed object with the 
 * larger value.
*/
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return b > a ? b : a;
}

/**
 * @brief Gets the raw bit representation of the fixed-point nbr.
 * 
 * @return The raw bits repersentation of the fixed-point nbr.
*/
int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
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

/**
 * @brief Converts the fixed-point value to a float.
 * 
 * @return The float representation of the fixed-point value.
*/
float Fixed::toFloat(void) const {
  return (float)_value / (1 << _frBits);
}

/**
 * @brief Converts the fixed-point value to an integer.
 * 
 * @return The int representation of the fixed-point value.
*/
int Fixed::toInt(void) const {
  return _value >> _frBits;
}

/**
 * @brief Overloaded insertion operator for Fixed class.
 * 
 * This operator allows for the insertion of a Fixed object's floating-point 
 * representation into an output stream. It converts the fixed-point value to 
 * a floating-point value using the toFloat() member function and inserts it 
 * into the provided output stream.
 * 
 * @param os The output stream object where the floating-point representation 
 *           of the Fixed object will be inserted.
 * @param number The Fixed object whose floating-point representation is to be 
 *               inserted into the output stream.
 * @return A reference to the output stream object.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& number) {
  os << number.toFloat();
  return os;
}
