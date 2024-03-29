#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange(void) {
	setDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& original) {
	for (std::map<std::string, float>::const_iterator it = original._database.begin(); it != original._database.end(); ++it) {
		std::string	key = it->first;
		float		value = it->second;
		_database.insert(std::make_pair(key, value));
	}
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {}
	return *this;
}

std::map<std::string, float>	BitcoinExchange::parseInput(const std::string& fileName) {
	std::map<std::string, float>	database;
	std::ifstream	file(fileName.c_str());
	if (!file.is_open()) {
		error(OPEN);
		return database;
	}

	std::string	line;
	int			errorCode;
	if (std::getline(file, line)) {
		while (std::getline(file, line)) {
			errorCode = parseLine(line);
			if (errorCode != OK)
				error(errorCode, errorCode == BAD_INPUT || errorCode == TOO_EARLY ? line : "");
		}
	}
	else {
		error(EMPTY);
		return database;
	}

	return database;
}

int	BitcoinExchange::parseLine(const std::string& line) {
	size_t	pipePos = line.find('|');
	if (pipePos == std::string::npos || line[pipePos - 1] != ' ' || line[pipePos + 1] != ' ')
		return BAD_INPUT;

	std::string	date = line.substr(0, pipePos - 1);
	std::string	amountString = line.substr(pipePos + 2);

	if (!isValidDate(date) || !isValidFloat(amountString))
		return BAD_INPUT;

	float	amount = atof(amountString.c_str());
	if (amount < 0)
		return TOO_SMALL;
	if (amount > 1000)
		return TOO_LARGE;

	float	value = processInput(date, amount);
	if (value == TOO_EARLY)
		return TOO_EARLY;
	std::cout << date << " => " << amount << " = " << value << std::endl;
	return OK;
}

float	BitcoinExchange::processInput(const std::string& date, float amount) {
	float	result = -1;
	for (std::map<std::string, float>::iterator it = _database.begin(); it != _database.end(); ++it) {
		if (inputDateExceeded(date, it->first)) {
			if (it == _database.begin())
				return TOO_EARLY;
			return result;
		}
		result = amount * it->second;
	}
	return result;
}

void	BitcoinExchange::setDatabase(void) {
	std::ifstream	file(DEFAULT_DB);
	if (!file.is_open()) {
		throw invalidDatabase();
	}

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t	commaPos = line.find(',');
		std::string	date = line.substr(0, commaPos);
		std::string	priceString = line.substr(commaPos + 1);
		if (!isValidDate(date) || !isValidFloat(priceString))
			throw invalidDatabase();
		float	price = atof(priceString.c_str());
		_database.insert(std::make_pair(date, price));
	}
}

bool	BitcoinExchange::inputDateExceeded(const std::string& input, const std::string& data) {
	int inputYear = atoi(input.substr(0, 4).c_str());
	int inputMonth = atoi(input.substr(5, 2).c_str());
	int inputDay = atoi(input.substr(8, 2).c_str());

	int dataYear = atoi(data.substr(0, 4).c_str());
	int dataMonth = atoi(data.substr(5, 2).c_str());
	int dataDay = atoi(data.substr(8, 2).c_str());

	if (inputYear < dataYear)
		return true;
	else if (inputYear > dataYear)
		return false;

	if (inputMonth < dataMonth)
		return true;
	else if (inputMonth > dataMonth)
		return false;

	if (inputDay < dataDay)
		return true;

	return false;
}

void	error(int errorCode, const std::string& errorLocation) {
	std::string	errorMessage;
	switch (errorCode) {
		case OPEN:
			errorMessage = "could not open file";
			break;
		case EMPTY:
			errorMessage = "input file empty";
			break;
		case BAD_INPUT:
			errorMessage = "bad input => ";
			break;
		case TOO_SMALL:
			errorMessage = "not a positive number";
			break;
		case TOO_LARGE:
			errorMessage = "too large a number";
			break;
		case TOO_EARLY:
			errorMessage = "date too early => ";
			break;
		default:
			errorMessage = "idk";
	}
	std::cerr << "Error: " << errorMessage << errorLocation << std::endl;
}

bool	isValidDate(const std::string& dateString) {
	if (dateString.length() != 10 || charCount(dateString, '-') != 2)
		return false;

	std::istringstream iss(dateString);
	int year, month, day;
	char dash1, dash2;
	iss >> year >> dash1 >> month >> dash2 >> day;

	if (iss.fail() || dash1 != '-' || dash2 != '-')
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			daysInMonth = 29;
		else
			daysInMonth = 28;
	}

	if (day > daysInMonth)
		return false;
	return true;
}

bool	isValidFloat(const std::string& floatString) {
	if (floatString.empty())
		return false;
	size_t pos = floatString.find_first_not_of("+-");
	if (pos == std::string::npos)
		return false;
	std::string	remainingString = floatString.substr(pos);
	pos = remainingString.find_first_not_of(DIGITS + std::string("."));
	if (pos != std::string::npos)
		return false;

	int	decimalPointCount = charCount(remainingString, '.');
	if (decimalPointCount > 1)
		return false;
	return true;
}

size_t	charCount(const std::string& input, char c) {
	size_t	count = 0;

	for (size_t it = 0; it < input.length(); it++) {
		if (input[it] == c)
			count++;
	}
	return count;
}
