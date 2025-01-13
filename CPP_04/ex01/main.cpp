/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 14:23:01 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
  Animal* animals[10];

  /*Create Dogs and Cats*/
  for (int i = 0; i < 5; i++) {
      animals[i] = new Dog();
  }
  for (int i = 5; i < 10; i++) {
      animals[i] = new Cat();
  }

  /*Invoke behavior*/
  for (int i = 0; i < 10; i++) {
      animals[i]->makeSound();
  }

  /*Clean up*/
  for (int i = 0; i < 10; i++) {
      delete animals[i];  // This should trigger Brain destructor via Dog/Cat destructors
  }

/*Subject test*/
  // const Animal* j = new Dog();
  // const Animal* i = new Cat();
  // delete j;//should not create a leak
  // delete i;
  // return 0;
}
