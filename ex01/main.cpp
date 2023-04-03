#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "error! wrong number of arguments\n";
		return -1;
	}
	RPN rpn;
	try
	{
		std::string expression(argv[1]);
		rpn.Compute(expression);
		std::stack<double> c = rpn.getContainer();
		if (c.size() != 1) {
			std::cout << "error! wrong expression\n";
			return -1;
		}
		std::cout << c.top() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return -1;
	}
	return 0;
}