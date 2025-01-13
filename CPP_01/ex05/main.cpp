/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:24:01 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/10 03:04:22 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
  Harl harl;

  std::cout << "Testing DEBUG level:" << std::endl;
  harl.complain("DEBUG");

  std::cout << "\nTesting INFO level:" << std::endl;
  harl.complain("INFO");

  std::cout << "\nTesting WARNING level:" << std::endl;
  harl.complain("WARNING");

  std::cout << "\nTesting ERROR level:" << std::endl;
  harl.complain("ERROR");

  std::cout << "\nTesting UNKNOWN level:" << std::endl;
  harl.complain("UNKNOWN");

  return 0; 
}
