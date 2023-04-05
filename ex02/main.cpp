#include "PmergeMe.hpp"

int pushNumber(std::string str, std::vector<int> &numbers) {
		int number = std::atoi(str.c_str());
		if (number < 0 || number == 0) {
			std::cout << "Error: wrong input\n";
			return -1;
		}
		numbers.push_back(number);
		return 0;
} 

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: no sequnce given\n";
		return -1;
	}
	std::vector<int> numbers;
	for (int i = 1; i < argc; i++) {
		std::string temp(argv[i]);
		while (size_t pos = temp.find_first_of(' ') != temp.npos) {
			std::string str = temp.substr(0, pos);
			temp = temp.substr(pos + 1);
			if (pushNumber(str, numbers) < 0) {
				return -1;
			}
		}
		if (pushNumber(temp, numbers) < 0) {
			return -1;
		}
	}
	PmergeMe PM;

	PM.makePairs(numbers);
	std::cout << "vector\n";
	std::vector<int> res = PM.sortVec();
	for (size_t i = 0; i < res.size(); i++) {
		std::cout << res[i] << '\n';
	}
	std::cout << "list\n";
	std::list<int> res2 = PM.sortList();
	std::list<int>::iterator it = res2.begin();
	while (it != res2.end()) {
		std::cout << *it << '\n';
		it++;
	}
}