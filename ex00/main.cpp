#include "BitcoinExchanger.hpp"

int main(int argc, char **argv){
	BitcoinExchanger B;

	int res = B.ReadDB();
	if (B.GetDB().size() == 0) {
		std::cerr << "Error: empty database.\n";
		return -1;
	}
	if (res < 0) {
		std::cerr << "Error: no database.\n";
		return -1;
	}
	if (argc < 2) {
		std::cerr << "Error: could not open file.\n";
		return -1;
	}
	std::string input_file(argv[1]);
	if (B.ReadInput(input_file) < 0) {
		std::cerr << "Error: could not open file.\n";
		return -1;
	}
}