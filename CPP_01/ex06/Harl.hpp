/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:13:00 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/14 12:13:14 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
# include <iostream>
#include <string> 

class Harl {
 void debug(void);
 void info(void);
 void warning(void);
 void error(void);
 
 public:
  Harl();
  void complain(std::string level);
  ~Harl();
};

#endif
