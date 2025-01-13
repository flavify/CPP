/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:27:23 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 20:23:54 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main() {
  int size = 5;

  Zombie* horde = zombieHorde(size, "Zuuum");
  for (int i = 0; i < size; ++i)
    horde->announce();
  delete [] horde;
}
