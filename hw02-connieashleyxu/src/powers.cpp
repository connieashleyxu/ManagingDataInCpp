#include "powers.h"

POWER_ID Power::getID()
{
	return mPowerID;
}

/********************************
STRENGTH POWER
*********************************/

// constructor for StrengthPower
StrengthPower::StrengthPower()
{
	mDescription = "Superhuman Strength";
	mPowerID = POWER_STRENGTH;
}

// use function for StrengthPower
std::string StrengthPower::use()
{
	return "SMASH!!";
}

// fight function for StrengthPower
int StrengthPower::fight(Power *otherPower)
{
	switch (otherPower->getID())
	{
	case POWER_FLIGHT:
	case POWER_INTEL:
		return -1; // Strength loses to Flight and Intelligence
	case POWER_GADGETS:
	case POWER_LASER:
	case POWER_NATIONAL:
		return 1; // Strength wins against Gadgets, Lasers, and Nationalism
	default:
		return 0; // Strength ties against Strength
	}
}

/********************************
FLIGHT POWER
*********************************/

// constructor for FlightPower
FlightPower::FlightPower()
{
	mDescription = "Ability to fly";
	mPowerID = POWER_FLIGHT;
}

// use function for FlightPower
std::string FlightPower::use()
{
	return "Can fly away, maybe far from this place.";
}

// fight function for FlightPower
int FlightPower::fight(Power *otherPower)
{
	switch (otherPower->getID())
	{
	case POWER_INTEL:
	case POWER_NATIONAL:
	case POWER_STRENGTH:
		return 1; // Flight wins against Intelligence, Nationalism, Strength
	case POWER_GADGETS:
	case POWER_LASER:
		return -1; // Flight loses to Gadgets, Lasers
	default:
		return 0; // Flight ties against Flight
	}
}

/********************************
LASER POWER
*********************************/

// constructor for LaserPower
LaserPower::LaserPower()
{
	mDescription = "Can shoot lasers";
	mPowerID = POWER_LASER;
}

// use function for LaserPower
std::string LaserPower::use()
{
	return "Shoots lasers from their eyes. PEWPEWPEW!";
}

// fight function for LaserPower
int LaserPower::fight(Power *otherPower)
{
	switch (otherPower->getID())
	{
	case POWER_FLIGHT:
	case POWER_INTEL:
	case POWER_NATIONAL:
		return 1; // Lasers wins against Flight, Intelligence, Nationalism
	case POWER_GADGETS:
	case POWER_STRENGTH:
		return -1; // Lasers loses to Gadgets, Strength
	default:
		return 0; // Lasers ties against Lasers
	}
}

/********************************
INTEL POWER
*********************************/

// constructor for IntelPower
IntelPower::IntelPower()
{
	mDescription = "Superhuman Intelligence";
	mPowerID = POWER_INTEL;
}

// use function for IntelPower
std::string IntelPower::use()
{
	return "Uses their intelligence to outsmart opponents.";
}

// fight function for IntelPower
int IntelPower::fight(Power *otherPower)
{
	switch (otherPower->getID())
	{
	case POWER_GADGETS:
	case POWER_NATIONAL:
	case POWER_STRENGTH:
		return 1; // Intelligence wins against Gadgets, Nationalism, Strength
	case POWER_FLIGHT:
	case POWER_LASER:
		return -1; // Intelligence loses to Flight, Lasers
	default:
		return 0; // Intelligence ties against Intelligence
	}
}

/********************************
GADGET POWER
*********************************/

// constructor for GadgetPower
GadgetPower::GadgetPower()
{
	mDescription = "Uses some crazy gadgets";
	mPowerID = POWER_GADGETS;
}

// use function for GadgetPower
std::string GadgetPower::use()
{
	return "Uses gadgets to gain an advantage.";
}

// fight function for GadgetPower
int GadgetPower::fight(Power *otherPower)
{
	switch (otherPower->getID())
	{
	case POWER_FLIGHT:
	case POWER_LASER:
	case POWER_NATIONAL:
		return 1; // Gadgets wins against Flight, Lasers, Nationalism
	case POWER_INTEL:
	case POWER_STRENGTH:
		return -1; // Gadgets loses to Intelligence, Strength
	default:
		return 0; // Gadgets ties against Gadgets
	}
}

/********************************
NATIONAL POWER
*********************************/

// constructor for NationalPower
NationalPower::NationalPower()
{
	mDescription = "A strong belief in their mother country";
	mPowerID = POWER_NATIONAL;
}

// use function for NationalPower
std::string NationalPower::use()
{
	return "Screams AMERICA F*** YEAH!!";
}

// fight function for National Power
int NationalPower::fight(Power *otherPower)
{
	switch (otherPower->getID())
	{
	case POWER_FLIGHT:
	case POWER_GADGETS:
	case POWER_INTEL:
	case POWER_LASER:
	case POWER_STRENGTH:
		return -1; // Nationalism loses against Flight, Gadgets, Intelligence, Lasers, Strength
	default:
		return 0; // Nationalism ties against Nationalism
	}
}

// define the getPowerID function
POWER_ID getPowerID(const std::string &powerStr)
{
	if (powerStr == "strength")
		return POWER_STRENGTH;
	else if (powerStr == "flight")
		return POWER_FLIGHT;
	else if (powerStr == "laser")
		return POWER_LASER;
	else if (powerStr == "intel")
		return POWER_INTEL;
	else if (powerStr == "gadget")
		return POWER_GADGETS;
	else
		return POWER_NATIONAL;
}

Power *powerFactory(const std::string &powerName)
{
	POWER_ID powerID = getPowerID(powerName);
	std::string description;

	switch (powerID)
	{
	case POWER_STRENGTH:
		description = "Superhuman Strength";
		return new StrengthPower();

	case POWER_FLIGHT:
		description = "Ability to fly";
		return new FlightPower();

	case POWER_LASER:
		description = "Can shoot lasers";
		return new LaserPower();

	case POWER_INTEL:
		description = "Superhuman Intelligence";
		return new IntelPower();

	case POWER_GADGETS:
		description = "Uses some crazy gadgets";
		return new GadgetPower();

	case POWER_NATIONAL:
		description = "A strong belief in their mother country";
		return new NationalPower();

	default:
		return nullptr; // invalid power
	}
}

std::ostream &operator<<(std::ostream &out, const Power &p)
{
	out << p.mDescription;
	return out;
}