#include "halfling.hxx"
#include "lightfoothalfling.hxx"
#include "generateFunctions.hxx"
#include "json.hpp"

#include <memory>
#include <random>
#include <stdexcept>
#include <cstdint>
#include <string>
#include <fstream>

using namespace nlohmann;

Halfling::Halfling(int speed, std::string race, std::string parent) :
	r_speed{ speed },
	r_raceName{ race },
	r_parentRace{ parent } 
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;
	
	r_languages = generateData(r_raceName, "languages");
	r_racialFeatures = generateData(r_raceName, "features");

}

std::unique_ptr<Race> Halfling::generate() {

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return std::make_unique<Halfling>();

		case 1:
			return LightfootHalfling::generate();

		default:
			throw std::runtime_error("UNREACHABLE");
	}
}

int Halfling::getSpeed() { return r_speed; }
std::string Halfling::raceName() { return r_raceName; }
std::string Halfling::parentRace() { return r_parentRace; }
