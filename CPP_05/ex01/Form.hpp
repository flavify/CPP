#pragma once

#include <iostream>
#include <string.h>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  /**Orthodox Canonical Form Elements*/
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other) = delete;
  ~Form() = default;

  /**Getters**/
  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  /**Member func to sign the form**/
  void beSigned(const Bureaucrat &bureaucrat);

  /**Exception classes**/
  class GradeTooHighException : public std::exception {
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
    const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &out, const Form &form);