#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm() = default;
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(PresidentialPardonForm const &other) = default;
  PresidentialPardonForm &operator=(PresidentialPardonForm const &other) = delete;
  ~PresidentialPardonForm()= default;

  void execute(Bureaucrat const &executor) const override;
};
