/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:29:48 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/23 16:03:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av) {
  if (ac == 1) {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < ac; i++) {
      std::string str = av[i];
      for (size_t j = 0; j < str.length(); j++)
        std::cout << static_cast<char>(toupper(str[j]));
    }
  }
  std::cout << std::endl;
  return (0);
}
