/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:49:26 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/28 19:27:49 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main() {
  std::cout << "\n-----------------------------------------------------------\n" \
            << std::endl;
  /*Test default constructor*/
  DiamondTrap defaultDT;
  std::cout << "Testing default constructor:" << std::endl;
  defaultDT.whoAmI();
  defaultDT.attack("the air");  // Should use ScavTrap's attack method

  std::cout << "\n-----------------------------------------------------------\n" \
            << std::endl;

  /*Test parameterized constructor*/
  DiamondTrap namedDT("Sparkles✨");
  std::cout << "Testing parameterized constructor:" << std::endl;
  namedDT.whoAmI();
  namedDT.attack("a practice target");

  std::cout << "\n-----------------------------------------------------------\n" \
            << std::endl;

  /*Test copy constructor*/
  DiamondTrap copiedDT(namedDT);
  std::cout << "Testing copy constructor:" << std::endl;
  copiedDT.whoAmI();
  copiedDT.attack("a shadow");

  std::cout << "\n-----------------------------------------------------------\n" \
            << std::endl;

  /* Test assignment operator*/
  DiamondTrap assignedDT;
  assignedDT = namedDT;
  std::cout << "Testing assignment operator:" << std::endl;
  assignedDT.whoAmI();
  assignedDT.attack("an imaginary guy");

  /*Check energy and hit points manipulations*/
  std::cout << "\nTesting hit point and energy point manipulations:" << std::endl;
  assignedDT.takeDamage(20);
  assignedDT.beRepaired(15);
  assignedDT.takeDamage(100);

  return 0;
}
