/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:47:58 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 00:55:47 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

/**Colors**/
# define RESET "\033[0m"

/*Wrong Animal*/
# define PURPLE "\033[1;38;2;219;112;219m"

/*Wrong Cat*/
# define ORANGE "\033[1;38;2;255;179;71m"



class WrongAnimal {

 protected:
  std::string _type;

 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal operator=(const WrongAnimal &other);
  virtual ~WrongAnimal();
  
  std::string getType () const;
  void makeSound() const;

};

#endif