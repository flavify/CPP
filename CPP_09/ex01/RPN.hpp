#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN {
	public:
  	int evaluate();
		RPN() = default;
  	RPN(const std::string &expression);
		RPN(const RPN &other) = default;
		RPN &operator=(const RPN &other) = default;
		~RPN() = default;

	private:
  	std::string expression;

  	bool isNumber(const std::string &token);
  	bool isOperator(const std::string &token);
		int applyOperator(int left, int right, char op);
};
