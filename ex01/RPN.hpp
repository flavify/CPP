#pragma once

#include <iostream>

class RPN {
	public:
  	int evaluate();
  	RPN(const std::string &expression);

	private:
  	std::string expression;

  	bool isNumber(const std::string &token);
  	bool isOperator(const std::string &token);
};