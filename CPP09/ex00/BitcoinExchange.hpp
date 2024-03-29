#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

# define DIGITS "0123456789"
# define DEFAULT_DB "data.csv"
# define OK 0
# define OPEN 1
# define EMPTY 2
# define BAD_INPUT 3
# define TOO_SMALL 4
# define TOO_LARGE 5
# define TOO_EARLY -1

size_t	charCount(const std::string&, char);
bool	isValidFloat(const std::string&);
bool	isValidDate(const std::string&);
void	error(int, const std::string& = "");

class	BitcoinExchange {
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange&);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(const BitcoinExchange&);

	std::map<std::string, float>	getDatabase(void) {
		return _database;
	}
	std::map<std::string, float>	parseInput(const std::string&);

	class	invalidDatabase: public std::exception {
	public:
		const char* what() const throw() {
			return "Error: missing or invalid data.csv file";
		}
	};



private:
	std::map<std::string, float>	_database;

	void	setDatabase(void);
	int		parseLine(const std::string&);
	float	processInput(const std::string&, float);
	bool	inputDateExceeded(const std::string&, const std::string&);
};

#endif
