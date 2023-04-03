#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits.h>
class BitcoinExchanger
{
	private:
		std::map<std::string, double> db;
	public:
		BitcoinExchanger();
		~BitcoinExchanger();
		BitcoinExchanger( BitcoinExchanger const &other );
		BitcoinExchanger & operator=( BitcoinExchanger const &other );

		int ReadDB();
		int ReadInput(std::string &path);
		void Print();
		void FindAndPrint(std::string &date, double multiplier);
		std::map<std::string, double> GetDB() const;
};
