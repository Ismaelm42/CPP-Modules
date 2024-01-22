#include "File.hpp"
#include <ios>
#include <iostream>
#include <string>
#include <fstream>

int	main()
{
	File	file;

	if (file.check_files() == false)
		return -1;
	file.replace_file();
	return 0;
}
