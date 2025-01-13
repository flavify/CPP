#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*Default constuctor*/
AForm::AForm()
    : _name("Empty Form"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {};

/*Parametrized constructor*/
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw AForm::GradeTooLowException();
  }
}

/*Copy constructor*/
AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

/*Getters*/
const std::string &AForm::getName() const { return _name; }

bool AForm::isSigned() const { return _isSigned; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

/*Member func to sign the form*/
void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (_isSigned) {
    throw std::runtime_error("Form is already signed");
  }
  if (bureaucrat.getGrade() > _gradeToSign) {
    throw AForm::GradeTooLowException();
  }
  _isSigned = true;
}

/*Exception classes*/
const char *AForm::GradeTooHighException::what() const noexcept {
  return ORANGE "Form grade is too high!" RESET;
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return ORANGE "Form grade is too low" RESET;
}

const char *AForm::FormNotSignedException::what() const noexcept {
  return ORANGE "Form has not been signed!" RESET;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << "Form: " << BLUE << form.getName() << "📝" << RESET
      << " | Signed: " << PINK << (form.isSigned() ? "Yes" : "No") << RESET
      << " | Grade to sign: " << PINK << form.getGradeToSign() << RESET
      << " | Grade to execute: " << PINK << form.getGradeToExecute() << RESET;
  return out;
}