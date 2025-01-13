/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:27:39 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 00:45:49 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * @brief Default constuctor.
 * 
 * Initializes a FragTrap with default values.
 * Prints a creation message to standard output.
*/
FragTrap::FragTrap() : ClapTrap("Default") {
  _hitpoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << D_GREEN "FragTrap default constructor called." 
            << RESET << std::endl;
}

/**
 * @brief Copy constructor.
 * 
 * Duplicates an existing FragTrap.
 * Prints a messge to the std output.
 * 
 * @param other A reference to the FragTrap
 * to copy.
*/
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << D_GREEN "FragTrap copy constructor called." 
            << RESET << std::endl;
  
}

/**
 * @brief Assignment operator for FragTrap.
 *
 * Copies all properties from the specified FragTrap to this instance.
 * Outputs an assignment operator message to standard output.
 * 
 * @param other A reference to the FragTrap to be assigned from.
 * @return Returns a reference to this instance after copying.
 */
FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << D_GREEN "FragTrap assignation operator called." 
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
 * @brief Parameterized constructor for FragTrap.
 *
 * Initializes a FragTrap with the provided name, 
 * setting hit points to 100, energy points to 100, 
 * and attack damage to 30.
 * Outputs a creation message to standard output.
 * 
 * @param newName A std::string representing 
 * the name of the new FragTrap.
 */
FragTrap::FragTrap(const std::string& newName) : ClapTrap(newName) {
  _hitpoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << D_GREEN "FragTrap constructor for " << _name 
            << " called." << RESET << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Handles clean-up as the FragTrap object is
 * destroyed.
 * Prints a messge to the std output.
*/
FragTrap::~FragTrap() {
  std::cout << D_GREEN "FragTrap destructor for " << _name 
            << " called." << RESET << std::endl;
}

/**
 * @brief Attacks a specified target.
 * 
 * @param target The name of the targt to attack.
*/
void FragTrap::attack(const std::string& target) {
  std::cout << "\n";
  if (_energyPoints > 0) {
    std::cout << D_GREEN "FragTrap " << _name << ATTACKS 
              << target << ", causing " << _attackDamage 
              << " points of damage!" << std::endl;
  }
}

/**
 * @brief Activates a unique social interaction 
 * by requesting a high five.
 *
 * Outputs a friendly message to standard output, 
 * encouraging team interaction and boosting morale.
 */
void FragTrap::highFivesGuys(void) {
  std::cout << D_GREEN "FragTrap " << _name << RESET \
            << " requests a high five!🙏" << std::endl;
}