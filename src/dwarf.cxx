#include "dwarf.hxx"
#include "hilldwarf.hxx"
#include "json.hpp"
#include "generateFunctions.hxx"

#include <memory>
#include <fstream>
#include <random>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

using namespace nlohmann;

Dwarf::Dwarf(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace { parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	static std::default_random_engine engine { 
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution { 
		0, static_cast<unsigned char>((tables[r_parentRace]["tool proficiencies"].size()-1))
	};

	r_toolProficiencies.push_back(tables[r_parentRace]["tool proficiencies"][distribution(engine)]);
	r_weaponProficiencies = generateData(r_parentRace, "weapon proficiencies");
	r_languages = generateData(r_parentRace, "languages");
	r_racialFeatures = generateData(r_parentRace, "features");
}

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

		default:
			throw std::runtime_error("UNREACHABLE");
	}
}

int Dwarf::getSpeed() { return r_speed; }
std::string Dwarf::raceName() { return r_raceName; }
std::string Dwarf::parentRace() { return r_parentRace; } 
