#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dbFilename) {
  loadDatabase(dbFilename);
}

void BitcoinExchange::processInputFile(const std::string &inputFilename) const {
  std::ifstream inputFile(inputFilename);
  if (!inputFile) {
    throw std::runtime_error("Error: could not open file.");
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    try {
      processLine(line);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}

void BitcoinExchange::loadDatabase(const std::string &dbFilename) {
  std::ifstream dbFile(dbFilename);
  if (!dbFile) {
    throw std::runtime_error("Error: could not open database file.");
  }

  std::string line;
  while (std::getline(dbFile, line)) {
    std::istringstream iss(line);
    std::string date;
    double rate;

    if (std::getline(iss, date, ',') && (iss >> rate)) {
      exchangeRates[date] = rate;
    }
  }
}

void BitcoinExchange::processLine(const std::string &line) const {
  std::istringstream iss(line);
  std::string date, pipe, valueStr;

  if (!(iss >> date >> pipe >> valueStr) || pipe != "|") {
    throw std::runtime_error("Error: bad input => " + line);
  }

  double value = parseValue(valueStr);
  auto rateIt = exchangeRates.lower_bound(date);

  if (rateIt == exchangeRates.end() || rateIt->first > date) {
    if (rateIt != exchangeRates.begin()) {
      --rateIt;
    } else {
      throw std::runtime_error("Error: no matching date in database.");
    }
  }

  double result = value * rateIt->second;
  std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
}

double BitcoinExchange::parseValue(const std::string &valueStr) const {
  double value;
  try {
    value = std::stod(valueStr);
  } catch (...) {
    throw std::runtime_error("Error: not a valid number.");
  }

  if (value < 0) {
    throw std::runtime_error("Error: not a positive number.");
  }
  if (value > 1000) {
    throw std::runtime_error("Error: too large a number.");
  }

  return value;
}
