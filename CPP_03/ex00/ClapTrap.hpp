/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:38:11 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/15 20:34:44 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

/***COLORS***/
# define RESET "\033[0m"

/**Robots**/
/*ClapTrap*/
# define CYAN "\033[1;36m"

/**Actions**/
/*Attack*/
# define RED "\033[1;31m"
# define ATTACKS RED " attacks " RESET
/*Take Damage*/
# define BLUE "\033[1;34m"
# define TAKES BLUE " takes " RESET
/*Repair*/
# define GREEN "\033[1;32m"
# define REPAIRS GREEN " repairs itself " RESET


/**
 * @class ClapTrap
 * @brief A class simulting ClapTrap, a robotic
 * fictional character with different capabilities.
 * 
 * This class provides private attributes such as 
 * the name, hit points, energy points and the 
 * attack damage of the ClapTrap. Furthermore, 
 * it offers methods for managing these attributes
 * through interactions like attacking, taking damage, 
 * and repairing.
*/
class ClapTrap {
 private:
  std::string _name;
  int _hitpoints;
  int _energyPoints;
  int _attackDamage;

 public:
  ClapTrap();
  ClapTrap(const std::string& newName);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  ~ClapTrap();

  int getEnergyPoints() const;
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
