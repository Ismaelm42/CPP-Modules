#include "Sed.hpp"

Sed::Sed()
{
	std::cout << "Please enter the filename: ";
	getline(std::cin, _filename);
	std::cout << "Please enter the string you want to replace: ";
	getline(std::cin, this->_s1);
	std::cout << "Enter the string with which you want to replace it: ";
	getline(std::cin, this->_s2);
}

bool	Sed::_open_infile()
{
	_infile.open(_filename.c_str(), std::fstream::in);
	if (_infile.fail() == true)
		return false;
	return true;
}

bool	Sed::_create_outfile()
{
	_outfile.open((_filename + ".replace").c_str(), std::fstream::out);
	if (_outfile.fail() == true)
		return false;
	return true;
}

bool	Sed::check_files()
{
	if (_open_infile() == false)
	{
		std::cerr << "Error: Could not open file: " << _filename << std::endl;
		return false;
	}
	else if (_create_outfile() == false)
	{
		std::cerr << "Error: Could not create " << _filename << ".replace" << std::endl;
		return false;
	}
	else if (_s1 == "")
	{
		_outfile << _infile.rdbuf();
		return false;
	}
	return true;
}

void	Sed::replace_file()
{
	std::string	buffer;

	while (std::getline(_infile, buffer))
	{
		std::size_t	index = 0;
		while (index < buffer.length())
		{
			std::size_t	pos = buffer.find(_s1, index);
			if (pos != std::string::npos)
			{
				_outfile << buffer.substr(index, pos - index) << _s2;
				index = pos + _s1.length();
			}
			else
			{
				_outfile << buffer.substr(index);
				index = buffer.length();
			}
		}
		if (_infile.eof() == false)
			_outfile << "\n";
	}
}

Sed::~Sed()
{
	if (this->_infile.is_open() == true)
		this->_infile.close();
	if (this->_outfile.is_open() == true)
		this->_outfile.close();
}
