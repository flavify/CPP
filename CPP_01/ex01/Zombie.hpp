/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:18:28 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:45:07 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie {
 private:
  std::string _name;

 public:
    Zombie(std::string zName);
    Zombie();
    void announce(void);
    void setName(std::string newName);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
