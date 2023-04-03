#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN( RPN const &other )
{
	*this = other;
}

RPN & RPN::operator=( RPN const &other )
{
	this->container = other.container;
	return(*this);
}

std::stack<double> &RPN::getContainer() {
	return container;
}

void RPN::Compute(std::string &expression) {
	for (size_t i = 0; i < expression.size(); i++) {
		if (std::isdigit(expression[i])) {
			container.push(expression[i] - '0');
		} else if (expression[i] != ' ') {
			if (container.size() < 2) {
				throw(std::runtime_error("error! wrong input"));
			}
			double number1, number2;
			number1 = container.top();
			container.pop();
			number2 = container.top();
			container.pop();
			switch (expression[i]) {
				case '+':
					container.push(number1 + number2);
					break;
				case '-':
					container.push(number2 - number1);
					break;
				case '*':
					container.push(number1 * number2);
					break;
				case '/':
					if (number1 == 0)
						throw(std::runtime_error("error! division by zero"));
					container.push(number2 / number1);
					break;
				default:
					throw(std::runtime_error("error! unknown token"));
			}
		}
	}
}