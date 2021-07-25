#include "halforc.hxx"
#include "generateFunctions.hxx"
#include "json.hpp"
#include "character.hxx"
#include <fstream>
#include <memory>
#include <random>
#include <cstdint>
#include <string>
#include <vector>

using namespace nlohmann;

HalfOrc::HalfOrc(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace{ parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;
	
	r_languages = generateData(r_raceName, "languages");
	r_racialFeatures = generateData(r_raceName, "features");
	r_skillProficiencies = generateData(r_raceName, "skill proficiencies");

}

int HalfOrc::getSpeed() { return r_speed; }
std::string HalfOrc::raceName() { return r_raceName; }
std::string HalfOrc::parentRace() { return r_parentRace; }

std::unique_ptr<Race> HalfOrc::generate() {
	return std::make_unique<HalfOrc>();
}
