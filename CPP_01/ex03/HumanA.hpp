/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 08:12:30 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:48:23 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
 private:
  std::string _name;
  Weapon&     _weapon;

 public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
    ~HumanA();
};

# endif
