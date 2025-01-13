#include "Form.hpp"
#include "Bureaucrat.hpp"

/*Default constuctor*/
Form::Form()
    : _name("Empty Form"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {};

/*Parametrized constructor*/
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}

/*Copy constructor*/
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

/*Getters*/
const std::string &Form::getName() const { return _name; }

bool Form::isSigned() const { return _isSigned; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

/*Member func to sign the form*/
void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (_isSigned) {
    throw std::runtime_error("Form is already signed");
  }
  if (bureaucrat.getGrade() > _gradeToSign) {
    throw Form::GradeTooLowException();
  }
  _isSigned = true;
}

/*Exception classes*/
const char *Form::GradeTooHighException::what() const noexcept {
  return ORANGE "Form grade is too high!" RESET;
}

const char *Form::GradeTooLowException::what() const noexcept {
  return ORANGE "Form grade is too low" RESET;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  out << "Form: " << BLUE << form.getName() << "📝" << RESET
      << " | Signed: " << PINK << (form.isSigned() ? "Yes" : "No") << RESET
      << " | Grade to sign: " << PINK << form.getGradeToSign() << RESET
      << " | Grade to execute: " << PINK << form.getGradeToExecute() << RESET;
  return out;
}