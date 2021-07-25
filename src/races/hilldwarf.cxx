#include "hilldwarf.hxx"
#include "dwarf.hxx"
#include "../generateFunctions.hxx"
#include "../json.hpp"

#include <memory>
#include <string>
#include <fstream>

using namespace nlohmann;

HillDwarf::HillDwarf(std::string race, std::string parent) :
	Dwarf::Dwarf(),
	r_raceName{ race },
	r_parentRace{ parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	for (std::string feature : tables[r_raceName]["features"]) {
		r_racialFeatures.push_back(feature);
	}
}

std::string HillDwarf::raceName() { return r_raceName; }
std::string HillDwarf::parentRace() { return r_parentRace; }

std::unique_ptr<Race> HillDwarf::generate() {
		return std::make_unique<HillDwarf>();
	}
