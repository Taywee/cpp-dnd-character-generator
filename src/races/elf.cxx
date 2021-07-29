#include "elf.hxx"
#include "race.hxx"
#include "../json.hpp"
#include "highelf.hxx"
#include "../generateFunctions.hxx"
#include <memory>
#include <random>
#include <cstdint>
#include <stdexcept>

Elf::Elf(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace{ parent }
{
	r_racialFeatures = generateData(r_raceName, "features");
	r_languages = generateData(r_raceName, "languages");
	r_skillProficiencies = generateData(r_raceName, "skill proficiencies");
}

std::unique_ptr<Race> Elf::generate(Proficiencies &proficiencies) {

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return std::make_unique<Elf>();

		case 1:
			return HighElf::generate();

		default:
			throw std::runtime_error("UNREACHABLE");
	}
}

int Elf::getSpeed() { return r_speed; }
std::string Elf::raceName() { return r_raceName; }
std::string Elf::parentRace() { return r_parentRace; }
