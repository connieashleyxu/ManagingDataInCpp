#include "strlib.h"

#include <sstream>

std::vector<std::string> strSplit(const std::string &str, char splitChar)
{
	std::vector<std::string> splitStrings;
	std::string strChar;
	std::istringstream strStream(str);

	while (std::getline(strStream, strChar, splitChar))
	{
		splitStrings.push_back(strChar);
	}

	return splitStrings;
}