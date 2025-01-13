/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:38:11 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 00:59:42 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

/***COLORS***/
# define RESET    "\033[0m"

/**Robots**/
/*ClapTrap*/
# define CYAN     "\033[1;36m"
/*ScavTrap*/
# define PURPLE   "\033[1;38;2;150;111;214m"
/*FragTrap*/
# define D_GREEN  "\033[1;38;5;22m"
/*DiamondTrap*/
# define TURQUISE "\033[1;38;2;64;224;208m"

/**Actions**/
/*Attack*/
# define RED      "\033[1;31m"
# define ATTACKS RED " attacks " RESET
/*Take Damage*/
# define BLUE     "\033[1;34m"
# define TAKES BLUE " takes " RESET
/*Repair*/
# define GREEN    "\033[1;32m"
# define REPAIRS GREEN " repairs itself " RESET

/**
 * @class ClapTrap
 * @brief A class simulating ClapTrap, a robotic 
 * fictional character with different capabilities.
 *
 * This class serves as a base class for different 
 * types of robotic characters. It provides protected 
 * attributes such as the name, hit points, energy points,
 * and attack damage, enabling derived classes to 
 * access these properties directly.
 * The class also includes virtual functions to allow 
 * for polymorphic behavior in derived classes.
 */
class ClapTrap {

 protected:
  std::string _name;
  int _hitpoints;
  int _energyPoints;
  int _attackDamage;

 public:
  ClapTrap();
  ClapTrap(const std::string& _name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  virtual ~ClapTrap();
  int getEnergyPoints() const;
  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
