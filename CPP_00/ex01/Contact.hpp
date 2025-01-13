/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:01:10 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 03:40:12 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact {

 private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickName;
  std::string _phoneNumber;
  std::string _darkestSecret;

 public:
  Contact();
  void setDetails(std::string _firstName, std::string _lastName, \
        std::string _nickName, std::string _phoneNumber, \
        std::string _darkestSecret);
  std::string truncate(std::string str);
  void displayShort(int idx);
  void displayFull();

  ~Contact();
};

#endif
