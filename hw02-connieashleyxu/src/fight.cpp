#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include "hero.h"
#include "fight.h"

bool loadHeroes(const std::string &fileName, std::vector<Hero *> &heroVector)
{
	std::ifstream inputFile(fileName);

	// error loading file
	if (!inputFile.is_open())
	{
		std::cerr << "Unable to load file \"" << fileName << "\"!" << std::endl;
		return false;
	}

	std::string line;
	bool errorOccurred = false;
	while (std::getline(inputFile, line))
	{
		// split line into parts
		std::vector<std::string> parts = strSplit(line, '|');

		if (parts.size() != 3)
		{
			std::cerr << "Invalid hero definition format in file \"" << fileName << "\"!" << std::endl;
			errorOccurred = true;
			inputFile.close();
			break;
		}

		// create hero object with valid data
		Hero *hero = new Hero(line);
		if (hero != nullptr)
		{
			heroVector.push_back(hero);
		}
	}

	inputFile.close();
	return !errorOccurred;
}

Hero *selectHero(std::vector<Hero *> &heroVector, const std::string &prompt, std::ostream &out, std::istream &in)
{
	int heroIndex;

	// select heroes
	out << prompt;
	in >> heroIndex;
	if (heroIndex < 0 || heroIndex >= heroVector.size())
	{
		std::cout << "Invalid hero selection." << std::endl;
		return nullptr;
	}

	return heroVector[heroIndex];
}

void heroCombat(Hero *heroA, Hero *heroB, std::ostream &output)
{
	// reset hero health
	heroA->resetHealth();
	heroB->resetHealth();

	output << "---------------------------------------" << std::endl;

	while (heroA->getHealth() > 0 && heroB->getHealth() > 0)
	{
		Power *powerA = heroA->useRandomPower();
		Power *powerB = heroB->useRandomPower();

		int result = powerA->fight(powerB);

		// display health of both heroes
		output << heroA->getName() << " has " << heroA->getHealth() << " health" << std::endl;
		output << heroB->getName() << " has " << heroB->getHealth() << " health" << std::endl;

		if (result == 1)
		{
			heroB->takeDamage();
			std::cout << heroA->getName() << " " << powerA->use() << std::endl;
			std::cout << heroB->getName() << " " << powerB->use() << std::endl;
			std::cout << powerA->getDescription() << " WINS" << std::endl;
		}
		else if (result == -1)
		{
			heroA->takeDamage();
			std::cout << heroA->getName() << " " << powerA->use() << std::endl;
			std::cout << heroB->getName() << " " << powerB->use() << std::endl;
			std::cout << powerB->getDescription() << " WINS" << std::endl;
		}
		else
		{
			heroA->takeDamage();
			heroB->takeDamage();
			std::cout << heroA->getName() << " " << powerA->use() << std::endl;
			std::cout << heroB->getName() << " " << powerB->use() << std::endl;
			std::cout << "TIE" << std::endl;
		}

		output << "---------------------------------------" << std::endl;
	}

	if (heroA->getHealth() <= 0 && heroB->getHealth() <= 0)
	{
		output << "TIE!" << std::endl;
	}
	else if (heroA->getHealth() <= 0)
	{
		output << heroB->getName() << " WINS!!!" << std::endl;
	}
	else
	{
		output << heroA->getName() << " WINS!!!" << std::endl;
	}
}

int fight(const std::string &inputFileName, const std::string &outputFileName, unsigned seed)
{
	std::vector<Hero *> heroes;
	std::ifstream inputFile(inputFileName);

	if (!inputFile.is_open())
	{
		std::cerr << "Unable to load file \"" << inputFileName << "\"!" << std::endl;
		return 1; // failed to load heroes
	}

	std::ofstream outputFile(outputFileName);

	if (!outputFile.is_open())
	{
		inputFile.close();
		std::cerr << "Unable to open output file \"" << outputFileName << "\"!" << std::endl;
		return 2; // failed to open output file
	}

	int result = fight(inputFile, outputFile, seed);

	inputFile.close();
	outputFile.close();

	return result;
}

int fight(std::istream &input, std::ostream &output, unsigned seed)
{
	// display seed
	std::srand(seed);
	output << "Seed: " << seed << std::endl;

	std::vector<Hero *> heroVector; // hero vector

	while (true)
	{
		int choice;
		std::string fileName;

		output << std::endl
			   << "Choose an option:" << std::endl;
		output << "1. Load Heroes" << std::endl;
		output << "2. Print Hero Roster" << std::endl;
		output << "3. Hero Fight!" << std::endl;
		output << "4. Quit" << std::endl;
		output << "> ";
		input >> choice;

		switch (choice)
		{
		case 1:
		{
			std::vector<Hero *> tempHeroVector; // temp vector for hero load

			// enter file to load heroes
			output << std::endl
				   << "Enter the file to load: ";
			input >> fileName;

			if (loadHeroes(fileName, tempHeroVector))
			{
				for (Hero *hero : heroVector)
				{
					delete hero;
				}

				heroVector = tempHeroVector;
			}

			break;
		}
		case 2:
		{
			// display loaded heroes
			output << std::endl
				   << "The following " << heroVector.size() << " heroes are loaded..." << std::endl;
			output << "---------------------------------------" << std::endl;

			for (const Hero *hero : heroVector)
			{
				output << *hero;
				output << "---------------------------------------" << std::endl;
			}
			break;
		}
		case 3:
		{
			// hero fight
			if (heroVector.size() < 2)
			{
				std::cout << std::endl
						  << "Not enough heroes to fight. Please load more heroes." << std::endl;
				break;
			}

			// display hero list
			output << std::endl;
			for (size_t i = 0; i < heroVector.size(); ++i)
			{
				output << i << ": " << heroVector[i]->getName() << std::endl;
			}
			Hero *heroA = nullptr;
			while (heroA == nullptr)
			{
				heroA = selectHero(heroVector, "Select your first hero: ", output, input);
			}

			Hero *heroB = nullptr;
			while (heroB == nullptr)
			{
				heroB = selectHero(heroVector, "Select your second hero: ", output, input);
			}

			// hero combat
			heroCombat(heroA, heroB, output);
			break;
		}
		case 4:
		{
			// exit
			output << std::endl
				   << "Goodbye" << std::endl;

			// free allocated memory in vector
			for (Hero *hero : heroVector)
			{
				delete hero;
			}
			heroVector.clear();
			return 0;
		}
		default:
			std::cout << "Invalid choice. Please select a valid option." << std::endl;
			break;
		}
	}
}
