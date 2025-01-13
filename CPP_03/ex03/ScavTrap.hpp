/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:59:07 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 01:02:51 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief A derived class from ClapTrap designed 
 * to model a more specialized character, 
 * known as ScavTrap.
 *
 * ScavTrap inherits from ClapTrap and extends 
 * it's functionality to include guarding gates 
 * and specialized attacks. It is more specialized
 * than a general ClapTrap and can be used in 
 * scenarios where gate guarding and security 
 * are required.
 */
class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const std::string& newName);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  ~ScavTrap();
  void attack(const std::string& target);
  void guardGate();
};

#endif