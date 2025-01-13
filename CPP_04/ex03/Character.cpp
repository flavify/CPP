/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:42:14 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 20:36:53 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character() : _name("Default") {
  for (int i = 0; i < 4; i++) {
    _inventory[i] = NULL;
  }
};

Character::Character(const std::string name) : _name(name) {
  for (int i = 0; i < 4; i++) {
    _inventory[i] = NULL;
  }
}

Character::Character(const Character &other) : _name(other._name) {
  copyInventory(other);
}

Character& Character::operator=(const Character &other) {
  if(this != &other) {
    _name = other._name;
    clearInventory();
    copyInventory(other);
  }
  return *this;
}

Character::~Character() {
  clearInventory();
}

std::string const& Character::getName() const {
  return _name;
}

void Character::equip(AMateria* m) {
  if (!m) return;
  for (int i = 0; i < 4; i++) {
    if(_inventory[i]==NULL) {
      _inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || \
      _inventory[idx] == NULL) return;
  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= 4 || \
    _inventory[idx] == NULL) return;
  _inventory[idx]->use(target);
}

void Character::clearInventory() {
  for(int i = 0; i < 4; i++) {
      delete _inventory[i];
      _inventory[i] = NULL;
  }
}

void Character::copyInventory(const Character& other) {
  for(int i = 0; i < 4; i++) {
    if(other._inventory[i] != NULL) {
      _inventory[i] = other._inventory[i]->clone();
    } else {
      _inventory[i] = NULL;
    }  
  }
}
