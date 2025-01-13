/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:20:07 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/29 02:44:14 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>

# define GRAY "\033[1;38;2;80;80;80m"
# define RESET "\033[0m"

class Brain {

 private:
    std::string _ideas[100];

 public:
    Brain();
    Brain(const Brain &other);
    Brain& operator=(const Brain &other);
    virtual ~Brain();
    std::string getIdea(int index) const;
    void setIdea(int index, std::string& idea);
};


#endif