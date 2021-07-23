#include "hilldwarf.hxx"
#include "dwarf.hxx"
#include "generateFunctions.hxx"
#include "json.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace nlohmann;

HillDwarf::HillDwarf(std::string race, std::string parent) :
	Dwarf(),
	r_raceName{ race },
	r_parentRace{ parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	for (std::string feature : tables["HillDwarf"]["features"]) {
		r_racialFeatures.push_back(feature);
	}
}

std::string HillDwarf::raceName() { return "HillDwarf"; }
std::string HillDwarf::parentRace() { return "Dwarf"; }

std::unique_ptr<Race> HillDwarf::generate() {
		return std::make_unique<HillDwarf>();
	}
