/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:27:46 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:41:27 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
  {
  Weapon club = Weapon("crude spiked club");
  HumanA bob("Bob", club);
  bob.attack();
  club.setType("some other type of club");
  bob.attack();
  }
  {
  Weapon club = Weapon("crude spiked club");
  HumanB jim("Jim");
  jim.setWeapon(club);
  jim.attack();
  club.setType("some other type of club");
  jim.attack();
  }
  return 0;
}
