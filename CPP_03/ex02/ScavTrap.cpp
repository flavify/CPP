/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:59:03 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 01:03:36 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/**
 * @brief Default constuctor.
 * 
 * Initializes a ScavTrap with default values.
 * Prints a creation message to standard output.
*/
ScavTrap::ScavTrap() : ClapTrap("Default") {
  _hitpoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << PURPLE "ScavTrap default constructor called." \
            << RESET << std::endl;
}

/**
 * @brief Copy constructor.
 * 
 * Duplicates an existing ScavTrap.
 * Prints a messge to the std output.
 * 
 * @param other A reference to the ScavTrap
 * to copy.
*/
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << PURPLE "ScavTrap copy constructor called." \
            << RESET << std::endl;
}

/**
 * @brief Assignment operator for ScavTrap.
 *
 * Copies all properties from the specified ScavTrap to this instance.
 * Outputs an assignment operator message to standard output.
 * 
 * @param other A reference to the ScavTrap to be assigned from.
 * @return Returns a reference to this instance after copying.
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << PURPLE "ScavTrap assignation operator called." \
            << RESET << std::endl;
  if (this != &other) {
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

/**
 * @brief Parameterized constructor for ScavTrap.
 *
 * Initializes a ScavTrap with the provided name 
 * and specific default values.

 * Outputs a creation message to standard output.
 * 
 * @param newName A std::string representing 
 * the name of the new ScavTrap.
 */
ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName) {
  _hitpoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << PURPLE "ScavTrap constructor for " << _name \
            << " called." << RESET << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Handles clean-up as the ScavTrap object is
 * destroyed.
 * Prints a messge to the std output.
*/
ScavTrap::~ScavTrap() {
  std::cout << PURPLE "ScavTrap destructor for " << _name \
            << " called." << RESET << std::endl;
}

/**
 * @brief Attacks a specified target.
 * 
 * @param target The name of the targt to attack.
*/
void ScavTrap::attack(const std::string& target)
{
    std::cout << "\n";
  if (_energyPoints > 0) {
    std::cout << PURPLE "ScavTrap " << _name << ATTACKS \
              << target << ", causing " << _attackDamage \
              << " points of damage!" << std::endl;
    _energyPoints --;
  } else {
    std::cout << PURPLE "ScavTrap " << _name << RESET \
              << " is too tired to attack!" << std::endl;
    std::cout << PURPLE "ScavTrap " << _name << RESET \
              << " will go take a nap." << std::endl;
  }
}

/**
 * @brief Activates Gatekeeper Mode.
 *
 * Puts ScavTrap into a defensive stance, 
 * enabling it to guard critical entries
 * or valuables.
 * Outputs a message to standard output 
 * indicating the mode activation.
 */
void ScavTrap::guardGate() {
  std::cout << PURPLE "ScavTrap " << _name \
            << RESET << " has entered in " \
            << "\033[1;96mGatekeeper Mode🛡️\n" \
            << RESET << std::endl;
}