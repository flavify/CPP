/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:35:30 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 02:04:04 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

 private:
  Brain *_brain;

 public:
  Cat();
  Cat(const Cat &other);
  Cat operator=(const Cat &other);
  virtual ~Cat();

  void makeSound() const;
};


#endif