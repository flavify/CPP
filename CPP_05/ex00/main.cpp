#include "Bureaucrat.hpp"

#include <iostream>

int main() {
  try {
    /*Create a Bureaucrat with a valid grade*/
    Bureaucrat john("John", 2);
    std::cout << john << std::endl;

    /*Increment the grade, making it 1 (highest possible)*/
    john.incrementGrade();
    std::cout << john << std::endl;

    /*Try incrementing beyond the highest grade, should throw exception*/
    john.incrementGrade();
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    /*Create another Bureaucrat with a valid grade*/
    Bureaucrat jane("Jane", 149);
    std::cout << jane << std::endl;

    /*Decrement the grade, making it 150 (lowest possible)*/
    jane.decrementGrade();
    std::cout << jane << std::endl;

    /*Try decrementing beyond the lowest grade, should throw exception*/
    jane.decrementGrade();
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    /*Try creating a Bureaucrat with an invalid high grade*/
    Bureaucrat invalidBureaucrat("Invalid", 0);
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    /*Try creating a Bureaucrat with an invalid low grade*/
    Bureaucrat invalidBureaucrat("Invalid", 151);
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}
