#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
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

		std::string check_data(std::string& line, int *date, float& value);
		void get_data_line(std::string& line, std::map<std::string, std::string>& container, int& key);
		void read_data(std::map<std::string, std::string>& container, std::map<std::string, std::string>::iterator& it, std::string& last_line, std::string& line);
		void output_data(std::map<std::string, std::string>& container);
		void get_data();
};

#endif
