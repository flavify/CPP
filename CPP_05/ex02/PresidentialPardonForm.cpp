#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << _target << " has been pardoned by Zaphod Beeblebrox.🖖"
            << std::endl;
}
