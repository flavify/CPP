/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:58:02 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/24 01:40:37 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

#define UP    "\033[A"
#define CUT   "\033[K"
#define BEGIN "\033[0G"
#define RESET "\033[0m"

//TODO: Cleanup main 

void diplayGreeting() {
  std::cout << UP << CUT << BEGIN;
  std::cout << "\n"
               "\033[38;2;255;192;203m██████╗░██╗░░██╗░█████╗░███╗░░██╗███████╗██████╗░░█████╗░░█████╗░██╗░░██╗\n"
               "\033[38;2;255;154;213m██╔══██╗██║░░██║██╔══██╗████╗░██║██╔════╝██╔══██╗██╔══██╗██╔══██╗██║░██╔╝\n"
               "\033[38;2;255;115;224m██████╔╝███████║██║░░██║██╔██╗██║█████╗░░██████╦╝██║░░██║██║░░██║█████═╝░\n"
               "\033[38;2;255;77;234m██╔═══╝░██╔══██║██║░░██║██║╚████║██╔══╝░░██╔══██╗██║░░██║██║░░██║██╔═██╗░\n"
               "\033[38;2;255;38;245m██║░░░░░██║░░██║╚█████╔╝██║░╚███║███████╗██████╦╝╚█████╔╝╚█████╔╝██║░╚██╗\n"
               "\033[38;2;255;0;255m╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚═╝░░╚══╝╚══════╝╚═════╝░░╚════╝░░╚════╝░╚═╝░░╚═╝\n" << std::endl;
  std::cout << RESET;
  std::cout << "\033[1m\033[38;2;64;224;208m";
  if (getenv("USER")) {
    std::cout << "Hi " << "\033[1m\033[93m" << getenv("USER") << "\033[0m" \
            << "\033[1m\033[38;2;64;224;208m, welcome to your phone book!" << "\U00002728" ;
  } else {
    std::cout << "Hi, welcome to your phone book!" <<  "\U00002728";
  }
  std::cout << "\n\n";
  std::cout << RESET << std::endl;
}


int main() {
  PhoneBook phoneBook;
  std::string command;

  diplayGreeting();

  while (true) {
    std::cout << "\033[38;2;255;105;180m" << \
          "Enter a command<ADD|SEARCH|EXIT>: " << "\033[0m";

    if (!std::getline(std::cin, command) && std::cin.eof())
      break;
    if (command == "ADD")
      phoneBook.addContact();
    else if (command == "SEARCH")
      phoneBook.searchContact();
    else if (command == "EXIT")
      break;
    else
      std::cout << "Invalid command" << std::endl;
  }
  exit(EXIT_SUCCESS);
}
