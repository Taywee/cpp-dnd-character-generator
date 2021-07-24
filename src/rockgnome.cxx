#include "rockgnome.hxx"
#include "gnome.hxx"
#include "generateFunctions.hxx"
#include "json.hpp"

#include <memory>
#include <string>
#include <fstream>

using namespace nlohmann;

RockGnome::RockGnome(std::string race, std::string parent) :
	Gnome::Gnome(),
	r_raceName{ race },
	r_parentRace{ parent } 
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	for (std::string feature : tables[r_raceName]["features"]) {
		r_weaponProficiencies.push_back(feature);
	}
}

std::string RockGnome::raceName() { return r_raceName; }
std::string RockGnome::parentRace() { return r_parentRace; }

std::unique_ptr<Race> RockGnome::generate() {
	return std::make_unique<RockGnome>();
}
