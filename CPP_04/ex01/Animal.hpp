/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:02:42 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/16 02:29:08 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

/**Colors**/
# define RESET "\033[0m"

/*Animal*/
# define GREEN "\033[1;38;2;120;205;120m"

/*Cat*/
# define PINK  "\033[1;38;2;255;160;200m"

/*Dog*/
# define BLUE   "\033[1;38;2;150;200;230m"


class Animal {
 protected:
  std::string _type;

 public:
  Animal();
  Animal(const Animal &other);
  Animal operator=(const Animal &other);
  virtual ~Animal();
  
  std::string getType () const;
  virtual void makeSound() const;
};

#endif