#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <string>

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm() = default;
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(RobotomyRequestForm const &other) = default;
  RobotomyRequestForm &operator=(RobotomyRequestForm const &other) = delete;
  ~RobotomyRequestForm() = default;

  void execute(Bureaucrat const &executor) const override;
};