/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 14:17:32 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
  // std::cout << "\n----------------------------------------\n";
  // std::cout << "Testing the Animal class\n\n";
  // Animal a;
  // std::cout << "Type of animal: " << a.getType() << std::endl;
  // a.makeSound();
  // std::cout << "\n----------------------------------------\n";
  // std::cout << "Testing the Cat class\n\n";
  // Cat b;
  // std::cout << "Type of animal: " << b.getType() << std::endl;
  // b.makeSound();
  // std::cout << "\n----------------------------------------\n";
  // std::cout << "Testing the Dog class\n\n";
  // Dog c;
  // std::cout << "Type of animal: " << c.getType() << std::endl;
  // c.makeSound();
  // std::cout << std::endl;

  /*Subject tests*/
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete j;
  delete i;

  /*Subject tests for Wrong*/
  const WrongAnimal* meta = new WrongAnimal();
  const WrongAnimal* i = new WrongCat();
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  meta->makeSound();
  delete meta;
  delete i;

  return 0;
}