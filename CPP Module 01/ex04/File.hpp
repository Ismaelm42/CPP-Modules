#ifndef FILE_HPP
#define FILE_HPP
#include <ios>
#include <iostream>
#include <string>
#include <fstream>

class File
{
	public:
		File();
		~File();
		bool	check_files();
		void	replace_file();

	private:
		std::fstream	_infile;
		std::fstream	_outfile;
		std::string		_filename;
		std::string		_s1;
		std::string		_s2;
		bool	_open_infile();
		bool	_create_outfile();
};

#endif
