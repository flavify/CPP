/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:02:46 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 18:17:51 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure& other);
  Cure &operator=(const Cure& other);
  ~Cure();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif
