/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:05:17 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 18:42:14 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zName) : _name(zName) {}

Zombie::~Zombie() {
  std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
