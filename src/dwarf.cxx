#include "dwarf.hxx"
#include "hilldwarf.hxx"
#include "json.hpp"
#include <memory>
#include <fstream>
#include <random>
#include <cstdint>
#include <string>
#include <vector>

using namespace nlohmann;

Dwarf::Dwarf(int speed) :
	r_speed { speed }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	for (std::string proficiencies : tables["Dwarf"]["weapon proficiencies"]) {
		r_weaponProficiencies.push_back(proficiencies);
	}

	static std::default_random_engine engine { 
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution { 
		0, static_cast<unsigned char>((tables["Dwarf"]["tool proficiencies"].size()-1))
	};

	r_toolProficiencies.push_back(tables["Dwarf"]["tool proficiencies"][distribution(engine)]);
}

int Dwarf::getSpeed() { return r_speed; }
std::string Dwarf::raceName() { return "Dwarf"; }
std::string Dwarf::parentRace() { return "Dwarf"; } 

std::unique_ptr<Race> Dwarf::generate() {
	
	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return std::make_unique<Dwarf>();
		
		case 1:
			return HillDwarf::generate();
	}
	__builtin_unreachable();
}

std::vector<std::string> Dwarf::generateLanguages() {
	
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> langs;

	for (std::string element : tables["Dwarf"]["languages"]) {
		langs.push_back(element);
	}

	return langs;
}

std::vector<std::string> Dwarf::generateRacialFeatures() {
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> features;

	for (std::string element : tables["Dwarf"]["features"]) {
		features.push_back(element);
	}

	return features;
}

