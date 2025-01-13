#pragma once

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange() = default;
  	BitcoinExchange(const std::string &dbFilename);
  	BitcoinExchange(const BitcoinExchange &other) = default;
		BitcoinExchange &operator=(const BitcoinExchange &other) = default;
		~BitcoinExchange() = default;

		void processInputFile(const std::string &inputFilename) const;

	private:
  	std::map<std::string, double> exchangeRates;

  	void loadDatabase(const std::string &dbFilename);
  	void processLine(const std::string &line) const;
  	double parseValue(const std::string &valueStr) const;
};

