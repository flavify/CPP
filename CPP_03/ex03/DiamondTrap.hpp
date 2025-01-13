/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:45:57 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 01:05:31 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/**
 * @class DiamondTrap
 * @brief Derived class from both ScavTrap 
 * and FragTrap to create a more versatile 
 * and powerful type of Trap.
 *
 * DiamondTrap inherits functionalities 
 * from both ScavTrap and FragTrap, 
 * combining their capabilities 
 * and adding unique features.
 */
class DiamondTrap : public ScavTrap, public FragTrap {
 private:
  std::string _name;

 public:
  DiamondTrap();
  DiamondTrap(const std::string& newName);
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap& operator=(const DiamondTrap& other);
  ~DiamondTrap();
  void attack(const std::string& target);
  void whoAmI();
};



#endif
