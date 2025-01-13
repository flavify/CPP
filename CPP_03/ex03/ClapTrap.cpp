/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:42:48 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/15 22:07:45 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @brief Default constuctor.
 * 
 * Initializes a ClapTrap with a default name, 
 * hit points, energy points, and attack damage.
 * Prints a creation message to standard output.
*/
ClapTrap::ClapTrap() : _name("Default"), _hitpoints(10), \
                    _energyPoints(10), _attackDamage(0) {
  std::cout << CYAN "ClapTrap default constructor called." \
            << RESET << std::endl;
}

/**
 * @brief Constructor with a name paramenter.
 * 
 * Initializes the ClapTrap's name, hit points, 
 * energy points, and attack damage.
 * Prints a creation message, including the name,
 * to standard output.
 * 
 * @param newName The name to assign to 
 * this ClapTrap.
*/
ClapTrap::ClapTrap(const std::string& newName) : _name(newName), \
           _hitpoints(10), _energyPoints(10), _attackDamage(0){
  std::cout << CYAN "ClapTrap constructor for " << _name \
            << " called." << RESET << std::endl;
}

/**
 * @brief Copy constructor.
 * 
 * Duplicates an existing ClapTrap.
 * Prints a messge to the std output.
 * 
 * @param other A reference to the ClapTrap.
 * to copy.
*/
ClapTrap::ClapTrap(const ClapTrap& other) {
  std::cout << CYAN "ClapTrap copy constructor called." \
            << RESET << std::endl;
  *this = other;
}

/**
 * @brief Copy assignment operator.
 * 
 * Assigns all the properties of another ClapTrap
 * to this one.
 * Prints a messge to the std output.
 * 
 * @param other The ClapTrap to get the attributes
 * from.
 * @return A reference to this ClapTrap object.
*/
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << CYAN "ClapTrap assignment operator called." \
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
 * @brief Destructor.
 * 
 * Handles clean-up as the ClapTrap object is
 * destroyed.
 * Prints a messge to the std output.
*/
ClapTrap::~ClapTrap() {
  std::cout << CYAN "ClapTrap destructor for "<< _name \
            << " called." << RESET << std::endl;
}

/**
 * @brief Energy points getter.
 * 
 * @return The current energy points as an int.
*/
int ClapTrap::getEnergyPoints() const {
  return _energyPoints;
}

/**
 * @brief Attacks a specified target.
 * 
 * @param target The name of the targt to attack.
*/
void ClapTrap::attack(const std::string& target) {
  std::cout << "\n";
  if (_energyPoints > 0) {
    std::cout << CYAN "ClapTrap " << _name << ATTACKS \
              << target << ", causing " << _attackDamage \
              << " points of damage!" << std::endl;
    _energyPoints--;
  } else {
    std::cout << CYAN "ClapTrap " << _name << RESET \
              << " is too tired to attack!" \
              << std::endl;
    std::cout << CYAN "ClapTrap " << _name \
              << RESET << " will go take a nap." \
              << std::endl;
  }
}

/**
 * @brief Takes damage, reducing the ClapTrap's
 * hit points by the specified amount.
 * 
 * @param amount The amount of dmg to be taken.
*/
void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "\n";
  std::cout << CYAN "ClapTrap " << _name << TAKES \
            << amount << " damage points!" \
            << std::endl;
  _hitpoints -= amount;
  if (_hitpoints <= 0) {
    _hitpoints = 0;
    std::cout << CYAN "ClapTrap " << _name << RESET \
              << " is already dead." << std::endl;
    std::cout << "Why are you stil hitting" \
              << CYAN " ClapTrap " << _name \
              << RESET << "?" << std::endl;
  }
}

/**
 * @brief Repairs ClapTrap, restoring a specified 
 * amount of hit points.
 * 
 * @param amount The amount of hitpoints to be
 * restored.
*/
void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "\n";
  if (_energyPoints > 0 && _hitpoints > 0) {
    std::cout << "So you tought you can defeat" \
              << " ClapTrap " << _name \
              << "?" << std::endl;
    std::cout << "Think again!" << std::endl;
    std::cout <<  CYAN "ClapTrap " << _name \
              <<  REPAIRS << " for " << amount \
              <<  " points!" << std::endl;
    _hitpoints += amount;
    _energyPoints --;
  } else {
    std::cout << CYAN "ClapTrap " << _name \
              << RESET << " is really dead this time." \
              << std::endl;
  }
}
