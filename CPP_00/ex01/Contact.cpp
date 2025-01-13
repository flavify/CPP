/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:53:44 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 03:40:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setDetails(std::string _firstName, std::string _lastName, \
      std::string _nickName, std::string _phoneNumber, \
      std::string _darkestSecret) {
  this->_firstName = _firstName;
  this->_lastName = _lastName;
  this->_nickName = _nickName;
  this->_phoneNumber = _phoneNumber;
  this->_darkestSecret = _darkestSecret;
}

std::string Contact::truncate(std::string str) {
  if (str.length() > 10)
    return str.substr(0, 9) + ".";
  return str;
}

void Contact::displayShort(int idx) {
  if (idx < 0 || idx > 7) {
    std::cout << "Invalid index" << std::endl;
    return;
  }
  std::cout << std::setw(10) << idx << "|";
  std::cout << std::setw(10) << truncate(_firstName) << "|";
  std::cout << std::setw(10) << truncate(_lastName) << "|";
  std::cout << std::setw(10) << truncate(_nickName) << "|" << std::endl;
}

void Contact::displayFull() {
  std::cout << "First name: " << _firstName << std::endl;
  std::cout << "Last name: " << _lastName << std::endl;
  std::cout << "Nick name: " << _nickName << std::endl;
  std::cout << "Phone number: " << _phoneNumber << std::endl;
  std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
