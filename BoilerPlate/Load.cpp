#include "Load.hpp"

std::vector<ship> Load::load()
{
	std::vector<ship> copy;
	utilities file;
	copy = file.explore((char *)"Models");
	return copy;
}