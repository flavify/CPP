/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:32:49 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 18:17:42 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);
  ~Ice();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};



#endif