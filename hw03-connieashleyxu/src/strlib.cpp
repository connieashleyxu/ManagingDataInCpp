#include "strlib.h"
#include <sstream>

std::vector<std::string> strSplit(const std::string &str, char splitChar)
{
	std::vector<std::string> result;
	std::string current;

	for (char ch : str)
	{
		if (ch == splitChar)
		{
			if (!current.empty())
			{
				result.push_back(current);
				current.clear();
			}
		}
		else
		{
			current += ch;
		}
	}

	if (!current.empty())
	{
		result.push_back(current);
	}

	return result;
}
