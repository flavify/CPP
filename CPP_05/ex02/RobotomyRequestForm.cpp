#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::srand(std::time(nullptr));
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << GRAY << "⚙️Bzzzzzz... drilling noises..." << RESET << std::endl;
  if (std::rand() % 2 == 0) { // 50% chance
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "The robotomy of " << _target << " has failed!" << std::endl;
  }
}
