#include "class.hxx"
#include "barbarian.hxx"
#include "cleric.hxx"
#include <memory>
#include <random>
#include <stdexcept>
#include <vector>
#include <string>

CharacterClass::~CharacterClass() {}

std::unique_ptr<CharacterClass> CharacterClass::generate() {
	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution {0, 1};

	switch (distribution(engine)) {
		case 0:
			return Barbarian::generate();
		case 1:
			return Cleric::generate();

		default:
			throw std::runtime_error("UNREACHABLE");
	}
}
