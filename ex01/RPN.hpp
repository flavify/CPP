#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN {
	public:
  	int evaluate();
  	RPN(const std::string &expression);

	private:
  	std::string expression;

  	bool isNumber(const std::string &token);
  	bool isOperator(const std::string &token);
		int applyOperator(int left, int right, char op)
};