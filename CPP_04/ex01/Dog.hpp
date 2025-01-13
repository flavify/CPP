/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:43:42 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 02:03:30 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

 private:
  Brain *_brain;

 public:
  Dog();
  Dog(const Dog &other);
  Dog operator=(const Dog &other);
  virtual ~Dog();

  void makeSound() const;
};

#endif
