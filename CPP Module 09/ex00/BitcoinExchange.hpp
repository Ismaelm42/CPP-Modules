#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <exception>

class BitcoinExchange
{	
	private:
		BitcoinExchange();
		std::string _data_name;
		std::string _input_name;
		std::ifstream _data;
		std::ifstream _input;

	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		bool check_header(bool output, std::ifstream& file);
		bool check_format(std::string& line);
		std::string check_date_and_value(std::string& line);
		void get_data_line(std::string& line, std::map<std::string, std::string>& container);
		void read_data(std::map<std::string, std::string>& container);
		void output_data(std::map<std::string, std::string>& container);
		void get_data();
};

#endif
