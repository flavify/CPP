#include "Intern.hpp"

AForm *createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *createPardon(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};
  AForm *(*formCreators[3])(const std::string &target) = {
      &createShrubbery, &createRobotomy, &createPardon};

  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formNames[i] << std::endl;
      return formCreators[i](target);
    }
  }

  std::cerr << "Error: Form name '" << formName << "' is unknown." << std::endl;
  return nullptr;
}
