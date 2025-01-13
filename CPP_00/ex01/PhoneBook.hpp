/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:54:13 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/16 09:38:35 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <string>
# include "Contact.hpp"

class PhoneBook {
  Contact contacts[8];
  int     index;

 public:
  PhoneBook();
  void addContact();
  void searchContact();
  void displayContacts();
  ~PhoneBook();
};

#endif
