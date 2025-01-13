#pragma once

#include <iostream>
#include <string.h>

class Bureaucrat;

class AForm {
protected:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  /**Orthodox Canonical AForm Elements*/
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other) = delete;
  virtual ~AForm() = default;

  /**Virtual func to make this class abstract**/
  virtual void execute(Bureaucrat const &executor) const = 0;

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

  class FormNotSignedException : public std::exception {
    const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);