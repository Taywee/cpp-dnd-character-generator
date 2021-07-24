#include "race.hxx"
#include "character.hxx"
#include "dwarf.hxx"
#include "gnome.hxx"
#include "human.hxx"
#include "elf.hxx"
#include "dragonborn.hxx"
#include "json.hpp"

#include <memory>
#include <stdexcept>
#include <random>
#include <cstdint>
#include <fstream>
#include <vector>

using namespace nlohmann;

Race::~Race() {}

std::unique_ptr<Race> Race::generate() {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;
	
	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {0, 4};
	
	switch (distribution(engine)) {
		case 0:
			return Dwarf::generate();
		case 1:
			return Human::generate();
		case 2:
			return Elf::generate();
		case 3:
			return Dragonborn::generate();
		case 4:
			return Gnome::generate();

		default:
			throw std::runtime_error("UNREACHABLE");

	}
}
