#include "BitcoinExchanger.hpp"

BitcoinExchanger::BitcoinExchanger()
{
}
BitcoinExchanger::~BitcoinExchanger()
{
}
BitcoinExchanger::BitcoinExchanger( BitcoinExchanger const &other )
{
	*this = other;
}
BitcoinExchanger & BitcoinExchanger::operator=( BitcoinExchanger const &other )
{
	this->db = other.db;
	return(*this);
}

int BitcoinExchanger::ReadDB() {
	std::ifstream infile("data.csv");
	std::string input = "";
	std::string date = "";
	std::string btc_value = "";
	int count = 0;

	if (!infile.is_open()) {
		return -1;
	}
	std::getline(infile, input);
	while (std::getline(infile, input)) {
		date = input.substr(0, input.find_first_of(','));
		btc_value = input.substr(input.find_first_of(',') + 1, input.npos);
		double btc_converted_value = std::strtod(btc_value.c_str(), NULL);
		db[date] = btc_converted_value;
		count++;
	}
	infile.close();
	return count;
}

double check_value(std::string &value, std::string &full_input) {
	if (value.size() == 0) {
		std::cout << "Error: bad input => " << full_input << '\n';
		return -1;
	}
	for (size_t i = 0; i < value.size();i++) {
		if (!isdigit(value[i]) && value[i] != '-' && value[i] != '.') {
			std::cout << "Error: bad input => " << full_input << '\n';
			return -1;
		}
	}
	long double converted_value = std::strtold(value.c_str(), NULL);
	if (converted_value > INT_MAX) {
		std::cout << "Error: too large a number\n";
		return -1;
	}
	if (converted_value < 0) {
		std::cout << "Error: not a positive number\n";
		return -1;
	}
	return converted_value;
}

bool check_date(std::string &date, std::string &full_input) {
	if (date.size() == 0 || date.size() != 10) {
		std::cout << "Error: bad input => " << full_input << '\n';
		return false;
	}
	struct tm tm;
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
		std::cout << "Error: bad input => " << full_input << '\n';
		return false;
	}
	return true;
}

void BitcoinExchanger::FindAndPrint(std::string &date, double multiplier) {
	std::map<std::string, double>::iterator it = db.upper_bound(date);
	if (it != db.begin()) {
		it--;
	}
	std::cout << date << " => " << multiplier << " = " << multiplier * it->second << '\n';
}

int BitcoinExchanger::ReadInput(std::string &path) {
	std::ifstream infile(path.c_str());
	std::string input = "";
	std::string date = "";
	std::string value = "";
	int count = 0;

	if (!infile.is_open()) {
		return -1;
	}
	std::getline(infile, input);
	while (std::getline(infile, input)) {
		if (input.find_first_of('|') != 11) {
			std::cout << "Error: bad input => " << input << '\n';
			continue;
		}
		date = input.substr(0, input.find_first_of(' '));
		if (!check_date(date, input)) {
			continue;
		}
		value = input.substr(input.find_first_of('|') + 2, input.npos);
		if (check_value(value, input) < 0) {
			continue;
		}
		long double multiplier = std::strtold(value.c_str(), NULL);
		FindAndPrint(date, multiplier);
		count++;
	}
	infile.close();
	return count;
}


std::map<std::string, double> BitcoinExchanger::GetDB() const {
	return db;
}