#pragma once 


#include <string>
#include <map>

class BitcoinExchange {
	public:
  	explicit BitcoinExchange(const std::string &dbFilename);
  	void processInputFile(const std::string &inputFilename) const;

	private:
  	std::map<std::string, double> exchangeRates;

  	void loadDatabase(const std::string &dbFilename);
  	void processLine(const std::string &line) const;
  	double parseValue(const std::string &valueStr) const;
};

