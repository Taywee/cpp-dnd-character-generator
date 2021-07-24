#include "human.hxx"
#include "generateFunctions.hxx"
#include "json.hpp"
#include "character.hxx"
#include <fstream>
#include <memory>
#include <random>
#include <cstdint>
#include <string>
#include <vector>

using namespace nlohmann;

Human::Human(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace{ parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;
	
	r_languages = generateData(r_parentRace, "languages");

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>((tables["languages"]).size()-1)
	};

	r_languages.push_back(tables["languages"][distribution(engine)]);

}

int Human::getSpeed() { return r_speed; }
std::string Human::raceName() { return r_raceName; }
std::string Human::parentRace() { return r_parentRace; }

std::unique_ptr<Race> Human::generate() {
	return std::make_unique<Human>();
}
