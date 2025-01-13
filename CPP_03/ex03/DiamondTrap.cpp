/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:51:28 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 01:09:51 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

/**
 * @brief Default constuctor.
 * 
 * Initializes a DiamondTrap with default values.
 * Prints a creation message to standard output.
*/
DiamondTrap::DiamondTrap() : ClapTrap("Default"), \
                            ScavTrap(), FragTrap() {

  _hitpoints = FragTrap::_hitpoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;

  std::cout << TURQUISE << "DiamondTrap default constructor called\n" 
            << RESET << std::endl;
}

/**
 * @brief Parameterized constructor for DiamondTrap.
 *
 * Initializes a DiamondTrap with the provided name 
 * and specific default values.

 * Outputs a creation message to standard output.
 * 
 * @param newName A std::string representing 
 * the name of the new DiamondTrap.
 */
DiamondTrap::DiamondTrap(const std::string& _name) : \
              ClapTrap(_name + "_clap_name"), \
              ScavTrap(_name), FragTrap(_name), _name(_name) {

  _hitpoints = FragTrap::_hitpoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;

  std::cout << TURQUISE << "DiamondTrap constructor for " << _name 
            << " called\n" << RESET << std::endl;
}

/**
 * @brief Copy constructor.
 * 
 * Duplicates an existing DiamondTrap.
 * Prints a messge to the std output.
 * 
 * @param other A reference to the DiamondTrap
 * to copy.
*/
DiamondTrap::DiamondTrap(const DiamondTrap& other) : \
              ClapTrap(other), ScavTrap(other), FragTrap(other) {
  _name = other._name;
  _hitpoints = other._hitpoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::cout << TURQUISE << "DiamondTrap copy constructor called\n" 
            << RESET << std::endl;
}

/**
 * @brief Assignment operator for DiamondTrap.
 *
 * Copies all properties from the specified DiamondTrap to this instance.
 * Outputs an assignment operator message to standard output.
 * 
 * @param other A reference to the DiamondTrap to be assigned from.
 * @return Returns a reference to this instance after copying.
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {

  std::cout << TURQUISE << "DiamondTrap assignation operator called\n" 
            << RESET << std::endl;

  if (this != &other) {
    ClapTrap::operator=(other);
    _name = other._name;
  }
  return *this;
}

/**
 * @brief Destructor.
 * 
 * Handles clean-up as the DiamondTrap object is
 * destroyed.
 * Prints a messge to the std output.
*/
DiamondTrap::~DiamondTrap() {
  std::cout << TURQUISE << "DiamondTrap destructor for " << _name 
            << " called" << RESET << std::endl;
}

/**
 * @brief Attacks a specified target.
 * 
 * @param target The name of the targt to attack.
*/
void DiamondTrap::attack(const std::string& target) {
  std::cout << "\n";
  ScavTrap::attack(target);
}

/**
   * @brief Reveals the identity of the DiamondTrap.
   *
   * Outputs the private name of the DiamondTrap 
   * and the names inherited to standard output.
   */
void DiamondTrap::whoAmI() {
  std::cout << "\n";
  std::cout << TURQUISE << "\nDiamondTrap name: " << _name \
            << CYAN << "\nClapTrap name: " << \
            ClapTrap::_name << RESET << std::endl;
}
