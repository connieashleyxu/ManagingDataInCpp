#include "fileio.h"
#include <iostream>
#include <fstream>
#include <string>

// Read in a file and modify the inputted vector of strings
// Use return value (true/false) to indicate success
bool getData(const std::string &inputLocation, std::vector<std::string> &data)
{
	// TODO: Complete the function
	data.clear(); // clear any previous data

	std::ifstream inputFile(inputLocation); // open input file
	if (!inputFile.is_open())
	{
		std::cout << "error opening file";
		return false; // open file failed
	}

	// std::string fileContent;
	// while (std::getline(inputFile, fileContent))
	// { // get file content line by line
	// 	if (!fileContent.empty())
	// 	{
	// 		std::cout << "getting line\n";
	// 		data.push_back(fileContent);
	// 	}
	// }

	// get file content with eof (to avoid error with empty line at the end of files)
	while (!inputFile.eof())
	{
		std::string fileContent;
		std::getline(inputFile, fileContent);

		data.push_back(fileContent);
	}

	inputFile.close(); // close file

	return true;
}

// Output the vector of strings to the inputted file name
// Use return value (true/false) to indicate success
bool putData(const std::string &outputLocation, const std::vector<std::string> &data)
{
	// TODO: Complete the function
	std::ofstream outputFile(outputLocation); // open output file
	if (!outputFile.is_open())
	{
		std::cout << "error opening file";
		return false; // open file failed
	}

	// for (auto fileContent : data)
	for (const std::string &fileContent : data)
	{ // fill out file content
		outputFile << fileContent << "\n";
		// std::cout << "Actual Line: " << fileContent << std::endl;
	}

	std::cout << "closing file";
	outputFile.close(); // close file

	return true;
}