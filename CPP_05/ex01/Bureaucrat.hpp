#pragma once

#include "Form.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

#define BLUE "\033[34m"
#define DPINK "\033[35m"
#define PINK "\033[38;2;255;105;180m"
#define RED "\033[38;2;255;128;128m"
#define ORANGE "\033[38;2;255;165;0m"
#define GREEN "\033[38;2;0;128;0m"
#define RESET "\033[0m"

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  /**Orthodox Canonical Form Elements*/
  Bureaucrat() = default;
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other) = delete;
  ~Bureaucrat() = default;

  /**Getters**/
  const std::string &getName() const;
  int getGrade() const;

  /**Grade Manipulation**/
  void incrementGrade();
  void decrementGrade();

  /**Method to sign a form**/
  void signForm(Form &form) const;

  /**Custom exception classes**/
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };
};

/**Insertion operator overload**/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc);
