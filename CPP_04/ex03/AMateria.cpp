/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:20:05 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 20:52:37 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type(NULL) {};

AMateria::AMateria(std::string const& type) : _type(type) {};

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria &other) {
  if (this != &other)
    _type = other._type;
  return *this;
}

AMateria::~AMateria() {};

std::string const& AMateria::getType() const {
  return _type;
}

void AMateria::use(ICharacter& target) {
  std::cout << "Using AMateria on " << target.getName()
            << std::endl;
}
