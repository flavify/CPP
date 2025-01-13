/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:56:36 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 00:58:43 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

 public:
  WrongCat();
  WrongCat(const WrongCat &other);
  WrongCat operator=(const WrongCat &other);
  virtual ~WrongCat();

  void makeSound() const;
};


#endif