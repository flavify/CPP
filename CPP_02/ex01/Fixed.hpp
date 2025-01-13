/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:50:31 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/14 18:48:15 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

/**
 * @class Fixed
 * @brief A class for reperesenting fixed-point numbers.
 * 
 * This class provides methods for handling fixed-point numbers
 * with a specific number of fractional bits(8). It is written
 * in the Orthodox Cannonical Form including a Default Constructor,
 * a Copy Constructor, a Copy Assignment Operator and a Destructor,
 * and methods to get and set the raw bit representation of the 
 * number. Aditionally, it provides conversions to floating-point
 * and integer values.
*/
class Fixed {
 private:
  int               _value;
  static const int  _frBits = 8;

 public:
  Fixed();
  Fixed(const int number);
  Fixed(float number);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
  void printOutput();
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif
