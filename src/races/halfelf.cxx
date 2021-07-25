#include "halfelf.hxx"
#include "highelf.hxx"
#include "../generateFunctions.hxx"
#include "../json.hpp"
#include <fstream>
#include <algorithm>
#include <memory>
#include <random>
#include <cstdint>
#include <string>
#include <vector>

using namespace nlohmann;

HalfElf::HalfElf(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace{ parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> temp_skills;
	for(std::string element : tables["skill proficiencies"])
		temp_skills.push_back(element);

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> languageDistribution {
		0, static_cast<unsigned char>((tables["languages"]).size()-1)
	};

	std::shuffle(temp_skills.begin(), temp_skills.end(), engine);

	r_languages = generateData(r_raceName, "languages");
	r_languages.push_back(tables["languages"][languageDistribution(engine)]);
	r_skillProficiencies.push_back(temp_skills[0]);
	r_skillProficiencies.push_back(temp_skills[1]);

}

int HalfElf::getSpeed() { return r_speed; }
std::string HalfElf::raceName() { return r_raceName; }
std::string HalfElf::parentRace() { return r_parentRace; }

std::unique_ptr<Race> HalfElf::generate() {
	return std::make_unique<HalfElf>();
}
