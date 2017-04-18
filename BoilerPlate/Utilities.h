#pragma once

#ifndef Utilities_H
#define Utilities_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>

namespace Engine
{
	namespace FileSystem
	{
		class Utilities
		{
			public:

				/*======================================*/
				/*			PUBLIC FUNCTIONS			*/
				/*======================================*/
	
				//List files
				std::vector<std::string> ListFile(std::string file);
				//Print util files name and content
				void printUtil(std::vector<std::string> list);
				//Build ifstream path
				std::string buildPath(std::string pre, std::string pos);

			protected:
				
				/*======================================*/
				/*			PROTECTED MEMBERS			*/
				/*======================================*/
				std::vector<std::string> list_of_files;
	
				/*======================================*/
				/*			PROTECTED FUNCTIONS			*/
				/*======================================*/
	
				//Creates path for file listing
				std::string getPath(std::string file);
				//Print File Content
				void printFileContent(std::string fileName);
		};
	}
}
#endif //Utilities_H