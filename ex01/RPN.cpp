#include "RPN.hpp"


RPN::RPN(const std::string &expression) : expression(expression) {}



bool RPN::isNumber(const std::string &token) {
  return token.size() == 1 && std::isdigit(token[0]);
}

bool RPN::isOperator(const std::string &token) {
  return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}


int RPN::applyOperator(int left, int right, char op) {
  switch (op) {
  case '+':
    return left + right;
  case '-':
  	return left - right;
  case '*':
    return left * right;
  case '/':
    if (right == 0) {
      throw std::invalid_argument("Error: Division by zero.");
    }
    return left / right;
  default:
    throw std::invalid_argument("Error: Unsupported operator.");
  }
}

int RPN::evaluate() {
  std::stack<int> operands;
  std::istringstream stream(expression);
  std::string token;

  while (stream >> token) {
    if (isNumber(token)) {
      operands.push(std::stoi(token));
  	} else if (isOperator(token)) {
      if (operands.size() < 2) {
        throw std::invalid_argument("Error: Not enough operands.");
      }
      int right = operands.top();
      operands.pop();
      int left = operands.top();
      operands.pop();
      operands.push(applyOperator(left, right, token[0]));
    } else {
      throw std::invalid_argument("Error: Invalid token in expression.");
    }
  }

  if (operands.size() != 1) {
    throw std::invalid_argument("Error: Invalid expression.");
  }

  return operands.top();
}