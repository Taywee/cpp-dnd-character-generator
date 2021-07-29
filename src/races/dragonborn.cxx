#include "dragonborn.hxx"
#include "../generateFunctions.hxx"
#include "../json.hpp"

#include <fstream>
#include <memory>
#include <cstdint>
#include <random>
#include <string>
#include <vector>

using namespace nlohmann;

Dragonborn::Dragonborn(Proficiencies &proficiencies) {
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>((tables[r_raceName]["features"].size()-1))
	};

	r_racialFeatures.push_back((tables[r_raceName]["features"][distribution(engine)]));
	r_languages = generateData(r_raceName, "languages");
}

int Dragonborn::getSpeed() { return r_speed; }
std::string Dragonborn::raceName() { return r_raceName; }
std::string Dragonborn::parentRace() { return r_parentRace; }

std::unique_ptr<Race> Dragonborn::generate(Proficiencies &proficiencies) {
	return std::make_unique<Dragonborn>(proficiencies);
}
