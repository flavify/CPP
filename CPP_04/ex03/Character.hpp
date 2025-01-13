/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:42:18 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 18:56:27 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
 private:
  std::string _name;
  AMateria* _inventory[4];

 public:
  Character();
  Character(const std::string name);
  Character(const Character& other);
  Character& operator=(const Character& other);
  ~Character();
  
  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
  
 private:
  void clearInventory();
  void copyInventory(const Character& other);
};

#endif
