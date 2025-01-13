/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:21:25 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 20:24:56 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zName) : _name(zName) {}

Zombie::Zombie() {
  _name = "Olaf";
}

Zombie::~Zombie() {
  std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::setName(std::string newName) {
  _name = newName;
}

void Zombie::announce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
