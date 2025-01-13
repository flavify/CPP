/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:15:07 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/10 03:08:53 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return (std::cout << "Usage: ./harlFilter <level>/<string>" \
            << std::endl, 1);

  Harl harl = Harl();
  std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string input = av[1];
	
	int idx = -1;
  for(int i = 0; i < 4; i++)
  {
		if (input == level[i])
		{
			idx = i;
			break;
		}
	}
	
	switch (idx)
	{
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]";
	}
	std::cout << std::endl;
  return 0;
}