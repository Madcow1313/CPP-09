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

	std::cout << "Before:	";
	for (size_t i = 0; i < numbers.size(); i++) {
		if (i % 10 == 0 && i != 0) {
			std::cout << "\n	";
		}
		std::cout << numbers[i] << ' ';
	}
	std::cout << '\n';
	PmergeMe PM;

	std::cout << "After:	";
	std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
	PM.makePairsVec(numbers);
	std::vector<int> res = PM.sortVec();
	std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();

	for (size_t i = 0; i < res.size(); i++) {
		if (i % 10 == 0 && i != 0) {
			std::cout << "\n	";
		}
		std::cout << res[i] << ' ';
	}
	std::cout << '\n';
	std::chrono::system_clock::time_point t3 = std::chrono::system_clock::now();
	PM.makePairsList(numbers);
	std::list<int> res2 = PM.sortList();
	std::chrono::system_clock::time_point t4 = std::chrono::system_clock::now();
	std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector : " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()  << " microseconds\n";
	std::cout << "Time to process a range of " << numbers.size() << " elements with std::list : " << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << " microseconds\n";
	// std::list<int>::iterator it = res2.begin();
	// while (it != res2.end()) {
	// 	std::cout << *it << '\n';
	// 	it++;
	// }
}