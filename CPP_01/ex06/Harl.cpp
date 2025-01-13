/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:13:26 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/15 02:47:46 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]\nI love having extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special";
  std::cout << "-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.";
  std::cout << " You didn’t put enough bacon in my burger!";
  std::cout << "  If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.";
  std::cout << " I’ve been coming for years whereas you started";
  std::cout << " working here since last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]\nThis is unacceptable!";
  std::cout << " I want to speak to the manager now." << std::endl; 
}

void Harl::complain(std::string level)
{
  std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*fun[4])(void) = {&Harl::debug, &Harl::info, \
                              &Harl::warning, &Harl::error};
  for(int i = 0; i < 4; ++i) {
    if (level == lvl[i]) {
      (this->*fun[i])();
      return ;
    }
  }
  std::cerr << "Level unknown." << std::endl;
}
