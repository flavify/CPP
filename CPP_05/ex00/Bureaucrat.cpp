#include "Bureaucrat.hpp"

#define BLUE "\033[34m"
#define PINK "\033[35m"
#define RED "\033[38;2;255;128;128m"
#define RESET "\033[0m"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) 
        : _name(other._name), _grade(other._grade) {}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  _grade--;
  if (_grade < 1)
    throw GradeTooHighException();
}
void Bureaucrat::decrementGrade() {
  _grade++;
  if (_grade > 150)
    throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return RED "Grade is too high!" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return RED "Grade is too low!" RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc) {
  out << BLUE << bc.getName() << RESET << "🧑💻, bureaucrat grade "
      << PINK << bc.getGrade() << RESET;
  return out;
}
