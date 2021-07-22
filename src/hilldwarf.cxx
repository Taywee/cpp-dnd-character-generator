#include "hilldwarf.hxx"
#include "dwarf.hxx"
#include "json.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace nlohmann;

HillDwarf::HillDwarf() :
	Dwarf(){}

std::string HillDwarf::raceName() { return "HillDwarf"; }
std::string HillDwarf::parentRace() { return "Dwarf"; }

std::unique_ptr<Race> HillDwarf::generate() {
		return std::make_unique<HillDwarf>();
	}

std::vector<std::string> HillDwarf::generateRacialFeatures() {
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> features;

	for (std::string feature : tables["Dwarf"]["features"]) {
		features.push_back(feature);
	}

	for(std::string feature : tables["HillDwarf"]["features"]) {
		features.push_back(feature);
	}

	return features;
}
