#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::srand(std::time(nullptr));
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::ofstream file(_target + "_shrubbery");
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file." << std::endl;
    return;
  }

  int treeType = std::rand() % 3;
  switch (treeType) {
  case 0:
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\ //  ~\n";
    file << "      //  \n";
    file << "     //    \n";
    file << "    ||     \n";
    file << "    ||     \n";
    break;
  case 1:
    file << "         *  \n";
    file << "        /|\\ \n";
    file << "       /*|O\\\n";
    file << "      /*/|\\*\\\n";
    file << "     /X/O|*\\X\\\n";
    file << "    /*/X/|\\O\\*\\\n";
    file << "   /O/*/X|*\\O\\X\\\n";
    file << "         |  \n";
    file << "         |  \n";
    break;
  case 2:
    file << "     *\n";
    file << "    ***\n";
    file << "   *****\n";
    file << "  *******\n";
    file << " *********\n";
    file << "***********\n";
    file << "    |||\n";
    file << "    |||\n";
    break;
  }

  file.close();
  std::cout << "Shrubbery created at: " << _target + "_shrubbery" << std::endl;
}
