/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:11:20 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/13 04:12:03 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  Zombie* save = newZombie("New Heap Zombie");
  randomChump("New Stack Zombie");
  delete save;
}
