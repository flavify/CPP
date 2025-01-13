/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:34:31 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 19:52:17 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
 protected:
  std::string _type;

 public:
  AMateria(std::string const& type);
  
  AMateria();
  AMateria(const AMateria& other);
  AMateria& operator=(const AMateria& other);
  virtual ~AMateria();

  std::string const& getType() const;
  
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};


#endif