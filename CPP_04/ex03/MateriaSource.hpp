/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:19:50 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/19 19:33:35 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* _materias[4];
  
 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  ~MateriaSource();
  
  virtual void learnMateria(AMateria* m);
  virtual AMateria* createMateria(std::string const& type);

 private:
  void deleteMaterias();
  void copyMaterias(const MateriaSource& other);
};

#endif