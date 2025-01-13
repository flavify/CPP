/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:26:32 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 01:00:38 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

/**
 * @class FragTrap
 * @brief A derived class from ClapTrap designed 
 * to model a more specialized character,
 * know as FragTrap .
 *
 * FragTrap inherits from ClapTrap and extends 
 * its functionality to include high-five 
 * interactions and specialized attacks.
 */
class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string& newName);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  ~FragTrap();
  void attack(const std::string& target);
  void highFivesGuys();
};

#endif
