/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:18:34 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:49:35 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
 private:
  std::string _name;
  Weapon*     _weapon;

 public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
    ~HumanB();
};

#endif
