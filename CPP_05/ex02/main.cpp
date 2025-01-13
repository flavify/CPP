#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  try {
    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 1: Bureaucrats and Forms Initialization" << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: Bureaucrats and Forms*/
    Bureaucrat john("John", 2);
    std::cout << "Bureaucrat: " << john << std::endl;
    Bureaucrat jane("Jane", 149);
    std::cout << "Bureaucrat: " << jane << std::endl;
    Bureaucrat jack("Jack", 50);
    std::cout << "Bureaucrat: " << jack << "\n" << std::endl;

    ShrubberyCreationForm shrubbery("Shrubbery");
    std::cout << shrubbery << std::endl;
    RobotomyRequestForm robotomy("Robotomy");
    std::cout << robotomy << std::endl;
    PresidentialPardonForm pardony("Pardony");
    std::cout << pardony << std::endl;

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 2: Signing and executing ShrubberyCreationForm"
              << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    jack.signForm(shrubbery);
    std::cout << shrubbery << std::endl;
    jane.executeForm(shrubbery);
    john.executeForm(shrubbery);

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 3: Signing and executing RobotomyRequestForm"
              << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    john.signForm(robotomy);
    std::cout << robotomy << std::endl;
    john.executeForm(robotomy);
    john.executeForm(robotomy);

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 4: Signing and executing PresidentialPardonForm"
              << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    john.signForm(pardony);
    std::cout << pardony << std::endl;
    john.executeForm(pardony);

  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}
