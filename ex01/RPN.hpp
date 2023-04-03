#pragma once
#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<double> container;
	public:
		RPN();
		~RPN();
		RPN( RPN const &other );
		RPN & operator=( RPN const &other );

		void Compute(std::string &expression);
		std::stack<double> &getContainer();
};
