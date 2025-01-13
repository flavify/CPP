#include "Intern.hpp"

int main() {
  Intern someRandomIntern;
  AForm *form;

  std::cout << "\n";
  form = someRandomIntern.makeForm("robotomy request", "Bender");
  if (form) {
    std::cout << *form << std::endl;
  }
  delete form;

  std::cout << "\n";
  form = someRandomIntern.makeForm("shrubbery creation", "Home");
  if (form) {
    std::cout << *form << std::endl;
  }
  delete form;

  std::cout << "\n";
  form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
  if (form) {
    std::cout << *form << std::endl;
  }
  delete form;

  std::cout << "\n";
  form = someRandomIntern.makeForm("unknown form", "Target");
  if (!form) {
    std::cerr << "Form creation failed." << std::endl;
  }
  delete form;

  return 0;
}
