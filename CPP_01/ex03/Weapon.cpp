/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:06:27 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:50:42 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type){}

Weapon::~Weapon(){}

const std::string& Weapon::getType() const{
  return _type;
}

void Weapon::setType(const std::string& type) {
  this->_type = type;
}
