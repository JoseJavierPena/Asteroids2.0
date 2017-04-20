#pragma once
#ifndef _LOAD_
#define _LOAD_

//
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//
#include "ship.hpp"
#include "dirent.h"
#include "Vector2.hpp"
#include "utilities.hpp"

class Load
{
public:
	std::vector<ship> load();
};

#endif // !_LOAD_