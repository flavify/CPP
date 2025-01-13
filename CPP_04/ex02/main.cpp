/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 14:17:53 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
  /*Uncommenting this should cause a compile-time error*/
  // Animal testAnimal;

  /*Array of pointers to Animal*/
  Animal* animals[2];

  /*Create instances of derived classes*/
  animals[0] = new Dog();
  animals[1] = new Cat();

  /*Invoke behavior*/
  for (int i = 0; i < 2; i++) {
      animals[i]->makeSound();
  }

  for (int i = 0; i < 2; i++) {
      delete animals[i];
  }

  return 0;
}
