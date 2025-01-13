/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:49:26 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 10:58:08 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
  /*Create two ClapTraps*/
  ClapTrap claptrap1("CT1");
  ClapTrap claptrap2("CT2");

  /*Display message on construction*/ 
  std::cout << "\n-->";
  std::cout << "Creating two ClapTraps" \
            << " named CT1 and CT2.\n";

  /*CT1 attacks CT2*/
  std::cout << "\n-->";
  std::cout << "CT1 attacks CT2:\n";
  claptrap1.attack("CT2");

  /*CT2 takes damage*/
  std::cout << "\n-->";
  std::cout << "CT2 takes damage:\n";
  claptrap2.takeDamage(2);

  /*CT2 tries to repair itself*/
  std::cout << "\n-->";
  std::cout << "CT2 attempts to repair" \
            << " itself:\n";
  claptrap2.beRepaired(5);

  /*CT1 attacks CT2 again*/
  std::cout << "\n-->";
  std::cout << "CT1 attacks CT2 again:\n";
  claptrap1.attack("CT2");

  /*Test energy depletion*/
  std::cout << "\n-->";
  std::cout << "CT1 keeps attacking until " \
            << "it runs out of energy:\n";
  while (claptrap1.getEnergyPoints() > 0){
    claptrap1.attack("CT2");
  }
  claptrap1.attack("CT2");

  return 0;
}