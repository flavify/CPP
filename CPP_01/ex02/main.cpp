/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 07:35:01 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/09 21:15:53 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
  /*string varible initialized to "HI THIS IS BRAIN"*/
  std::string str = "HI THIS IS BRAIN";
  /*a pointer to the string*/
  std::string* stringPTR = &str;
  /*a refrence to the string*/
  std::string& stringREF = str;

  std::cout << "Address of string variable:    " << &str << std::endl;
  std::cout << "Adress held by stringPTR:      " << stringPTR << std::endl;
  std::cout << "Adress held by stringREF:      " << &stringREF << std::endl;
  std::cout << std::endl;
  std::cout << "Value of the string variable:  " << str << std::endl;
  std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
