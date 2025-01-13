/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:46:33 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 18:24:51 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {};

Ice::Ice(const Ice& other) : AMateria(other) {};

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Ice::~Ice() {};

AMateria* Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName()
            << " *" << std::endl; 
}
