#include "dwarf.hxx"
#include "hilldwarf.hxx"
#include "../json.hpp"
#include "../generateFunctions.hxx"

#include <memory>
#include <fstream>
#include <random>
#include <cstdint>
#include <stdexcept>
#include <string>

using namespace nlohmann;

Dwarf::Dwarf(Proficiencies &proficiencies) {
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	static std::default_random_engine engine { 
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution { 
		0, static_cast<unsigned char>((tables[r_raceName]["tool proficiencies"].size()-1))
	};

        // TODO: this can loop forever if all tool proficiencies are already filled.
	while (!proficiencies.add(Proficiency("Tool", tables[r_raceName]["tool proficiencies"][distribution(engine)]))) {
	}
	for (const auto &proficiency: generateData(r_raceName, "weapon proficiencies")) {
            proficiencies.add(Proficiency("Weapon", proficiency));
	}
	r_languages = generateData(r_raceName, "languages");
	r_racialFeatures = generateData(r_raceName, "features");
}

std::unique_ptr<Race> Dwarf::generate(Proficiencies &proficiencies) {
	
	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return std::make_unique<Dwarf>(proficiencies);
		
		case 1:
			return HillDwarf::generate(proficiencies);

		default:
			throw std::runtime_error("UNREACHABLE");
	}
}

int Dwarf::getSpeed() { return r_speed; }
std::string Dwarf::raceName() { return r_raceName; }
std::string Dwarf::parentRace() { return r_parentRace; } 
