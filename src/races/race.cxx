#include "race.hxx"
#include "dwarf.hxx"
#include "gnome.hxx"
#include "halfling.hxx"
#include "halforc.hxx"
#include "human.hxx"
#include "elf.hxx"
#include "dragonborn.hxx"
#include "halfelf.hxx"
#include "tiefling.hxx"

#include <memory>
#include <stdexcept>
#include <random>
#include <cstdint>

Race::~Race() {}

std::unique_ptr<Race> Race::generate(Proficiencies &proficiencies) {

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {0, 8};
	
	switch (distribution(engine)) {
		case 0:
			return Dwarf::generate(proficiencies);
		case 1:
			return Human::generate(proficiencies);
		case 2:
			return Elf::generate(proficiencies);
		case 3:
			return Dragonborn::generate(proficiencies);
		case 4:
			return Gnome::generate(proficiencies);
		case 5:
			return Halfling::generate(proficiencies);
		case 6:
			return HalfElf::generate(proficiencies);
		case 7:
			return HalfOrc::generate(proficiencies);
		case 8:
			return Tiefling::generate(proficiencies);

		default:
			throw std::runtime_error("UNREACHABLE");

	}
}
