/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:54:16 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 03:40:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

PhoneBook::~PhoneBook() {}

void get_input(std::string& str, std::string prompt) {
  
  while(str.empty()) {
    std::cout << prompt;
    std::getline(std::cin, str);
    if (!std::cin || std::cin.eof())
      exit(EXIT_FAILURE);
  }
}

void PhoneBook::addContact() {
  if (index > 7)
    std::cout << "Repalcing the oldest contact" << std::endl;
  std::string _firstName, _lastName, \
        _nickName, _phoneNumber, _darkestSecret;

  get_input(_firstName, "Enter first name: ");
  get_input(_lastName, "Enter last name: ");
  get_input(_nickName, "Enter nick name: ");
  get_input(_phoneNumber, "Enter phone number: ");
  get_input(_darkestSecret, "Enter darkest secret: ");
  contacts[index % 8].setDetails(_firstName, _lastName, _nickName, \
                    _phoneNumber, _darkestSecret);
  index++;
}

void PhoneBook::searchContact() {
  int idx = 0;
  std::string input;

  displayContacts();
  std::cout << "Enter the index of the contact to want to view: ";
  std::getline(std::cin, input);
  if (!std::cin || std::cin.eof())
    exit(1);
  if (input.length() > 1 || !isdigit(input[0])) {
    std::cout << "Invalid index: index must be a single digit." << std::endl;
    return;
  }
  idx = input[0] - '0';
  if (idx < 0 || idx > 7 || idx >= index) {
    std::cout << "Invalid index: index is out of allowed range." \
               << std::endl;
    return;
  }
  contacts[idx].displayFull();
}

void PhoneBook::displayContacts() {
  std::cout << std::setw(10) << "Index" << "|";
  std::cout << std::setw(10) << "First name" << "|";
  std::cout << std::setw(10) << "Last name" << "|";
  std::cout << std::setw(10) << "Nick name" << "|" << std::endl;
  for (int i = 0; i < index; i++)
    contacts[i].displayShort(i);
}
