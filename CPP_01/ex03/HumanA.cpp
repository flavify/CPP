/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 02:18:13 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:48:49 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name,Weapon& weapon) \
      : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const {
  std::cout << _name << " attacks with their " << \
            _weapon.getType() << std::endl;
}
