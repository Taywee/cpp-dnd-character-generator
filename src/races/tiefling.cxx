#include "tiefling.hxx"
#include "../generateFunctions.hxx"
#include "../json.hpp"
#include <fstream>
#include <memory>
#include <random>
#include <cstdint>
#include <string>
#include <vector>

using namespace nlohmann;

Tiefling::Tiefling(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace{ parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;
	
	r_languages = generateData(r_raceName, "languages");
	r_racialFeatures = generateData(r_raceName, "features");
	r_cantrips.push_back("thaumaturgy");

}

int Tiefling::getSpeed() { return r_speed; }
std::string Tiefling::raceName() { return r_raceName; }
std::string Tiefling::parentRace() { return r_parentRace; }

std::unique_ptr<Race> Tiefling::generate() {
	return std::make_unique<Tiefling>();
}
