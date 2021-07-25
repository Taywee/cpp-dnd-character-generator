#include "highelf.hxx"
#include "elf.hxx"
#include "generateFunctions.hxx"
#include "json.hpp"

#include <memory>
#include <random>
#include <string>
#include <fstream>

using namespace nlohmann;

HighElf::HighElf(std::string race, std::string parent) :
	Elf::Elf(),
	r_raceName{ race },
	r_parentRace{ parent } 
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	for (std::string proficiency : tables[r_raceName]["weapon proficiencies"]) {
		r_weaponProficiencies.push_back(proficiency);
	}

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>((tables["wizard cantrips"]).size()-1)
	};

	r_cantrips.push_back(tables["wizard cantrips"][distribution(engine)]);

}

std::string HighElf::raceName() { return r_raceName; }
std::string HighElf::parentRace() { return r_parentRace; }

std::unique_ptr<Race> HighElf::generate() {
	return std::make_unique<HighElf>();
}
