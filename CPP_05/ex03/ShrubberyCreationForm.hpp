#pragma once

#include "AForm.hpp"

#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm() = default;
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &other) = default;
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other) = delete;
  ~ShrubberyCreationForm() = default;
  
  void execute(Bureaucrat const &executor) const override;
};