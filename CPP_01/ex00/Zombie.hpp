/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:53:53 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:45:03 by fvoicu           ###   ########.fr       */
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
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
