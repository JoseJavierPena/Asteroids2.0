#pragma once
#ifndef _UTILITIES_
#define _UTILITIES_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

//
#include "dirent.h"

//
#include "Vector2.hpp"
#include "ship.hpp"

class utilities
{
public: 
		utilities();
		~utilities();
		std::vector<ship> explore(char *dir_name);

private: 
		 DIR* dir;
		 struct dirent *entry;
		 struct stat info;
		 std::string readString;
		 std::fstream file;
		 std::vector<ship> Ship;	 
};

#endif // !_UTILITIES_