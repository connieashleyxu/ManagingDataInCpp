#include "cypher.h"
#include <cctype>

// Encrypts 2nd input
void substitutionCypherEncrypt(const std::string &cypher, const std::string &input, std::string &output)
{
	// TODO: Complete the function

	output = ""; // initialize output string

	for (char c : input)
	{
		if (std::isalpha(c)) // process only alphabetic characters
		{
			char encrypted;
			if (std::isupper(c))
			{
				encrypted = cypher[c - 'A']; // find cypher character for uppercase
			}
			else if (std::islower(c))
			{
				encrypted = cypher[c - 'a']; // find cypher character for lowercase
			}
			output += (std::islower(c) ? std::tolower(encrypted) : encrypted); // append encrypted character to output
		}
		else
		{
			output += c; // append non-alphabetic characters
		}
	}
}

// Decrypts 2nd input
void substitutionCypherDecrypt(const std::string &cypher, const std::string &input, std::string &output)
{
	// TODO: Complete the function

	output = ""; // initialize output string

	for (char c : input)
	{
		if (std::isalpha(c)) // process only alphabetic characters
		{
			size_t index;
			if (std::isupper(c))
			{
				index = cypher.find(std::toupper(c)); // find index of character in cypher for uppercase
			}
			else
			{
				index = cypher.find(std::toupper(c)); // find index of character in cypher for lowercase
			}

			if (index != std::string::npos) // if found in cypher
			{
				char decrypted = static_cast<char>((std::isupper(c) ? 'A' : 'a') + index); // find decrypted character
				output += decrypted;													   // append decrypted character to output
			}
		}
		else
		{
			output += c; // append non-alphabetic characters
		}
	}
}