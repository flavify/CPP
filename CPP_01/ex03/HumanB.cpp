/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:21:50 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 22:13:57 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
  this->_weapon = &weapon;
}

void HumanB::attack() const {
  if (!_weapon)
    std::cout << _name << " has no weapon" << std::endl;
  std::cout << _name << " attacks with their " << \
               _weapon->getType() << std::endl;
}
