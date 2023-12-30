#include "hero.h"
#include "fight.h"
#include "strlib.h"

#include <iostream>
#include <sstream>
#include <random>

Hero::Hero(const std::string &heroDef)
{
	std::vector<std::string> parts = strSplit(heroDef, '|');

	// initialize hero
	mName = parts[0];
	mMaxHealth = std::stoi(parts[2]);
	mHealth = mMaxHealth;

	std::vector<std::string> powers = strSplit(parts[1], ',');
	for (const std::string &powerStr : powers)
	{
		Power *power = powerFactory(powerStr);
		if (power != nullptr)
		{
			mPowers.push_back(power);
		}
	}
}

std::string Hero::getName()
{
	return mName;
}

Power *Hero::useRandomPower()
{
	if (mPowers.empty())
	{
		return nullptr; // no powers available
	}

	int randomIndex = (std::rand() % (mPowers.size()));

	return mPowers[randomIndex];
}

int Hero::getHealth()
{
	return mHealth;
}

void Hero::takeDamage()
{
	if (mHealth > 0)
	{
		mHealth--;
	}
}

void Hero::resetHealth()
{
	mHealth = mMaxHealth;
}

std::ostream &operator<<(std::ostream &out, const Hero &h)
{
	// display hero powers
	out << h.mName << " has the following powers..." << std::endl;
	for (const Power *power : h.mPowers)
	{
		std::cout << "\t" << power->getDescription() << std::endl;
	}
	return out;
}