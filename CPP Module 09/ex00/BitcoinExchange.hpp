#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <stdlib.h>

class BitcoinExchange
{	
	private:
		BitcoinExchange();
		std::map<std::string, std::string> _container;
		std::map<std::string, std::string>::iterator _it;
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
		void get_data_line(std::string& line);
		void read_data();
		void output_data();
		void get_data();
};

#endif
