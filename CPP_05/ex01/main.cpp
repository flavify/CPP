#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    std::cout << GREEN << "===================" << std::endl;
    std::cout << "Test 1: Default Constructor" << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: default constructor*/
    Form emptyForm;
    std::cout << emptyForm << std::endl;

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 2: Bureaucrats and Forms Initialization" << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: Bureaucrats and Forms*/
    Bureaucrat john("John", 2);
    Bureaucrat jane("Jane", 149);
    Bureaucrat jack("Jack", 50);

    Form formA("Form A", 1, 5);
    Form formB("Form B", 50, 50);
    Form formC("Form C", 150, 150);

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;
    std::cout << formC << std::endl;

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout
        << "Test 3: John (grade 2) tries to sign Form A (requires grade 1)"
        << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: John (grade 2) tries to sign Form A (needs grade 1)*/
    john.signForm(formA);
    std::cout << formA << std::endl;

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout
        << "Test 4: Jack (grade 50) tries to sign Form B (requires grade 50)"
        << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: Jack (grade 50) tries to sign Form B (needs grade 50)*/
    jack.signForm(formB);
    std::cout << formB << std::endl;

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout
        << "Test 5: Jane (grade 149) tries to sign Form C (requires grade 150)"
        << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: Jane (grade 149) tries to sign Form C (needs grade 150)*/
    jane.signForm(formC);
    std::cout << formC << std::endl;

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 6: Trying to sign an already signed Form B" << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: Trying to sign an already signed form*/
    jack.signForm(formB);

    std::cout << GREEN << "\n===================" << std::endl;
    std::cout << "Test 7: Creating a form with invalid grades (0 and 151)"
              << std::endl;
    std::cout << "===============================" << RESET << std::endl;
    /*Test: Creating a form with invalid grades*/
    try {
      Form invalidForm("Invalid Form", 0, 151);
    } catch (const std::exception &e) {
      std::cerr << "Exception caught during form creation: " << e.what()
                << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}
