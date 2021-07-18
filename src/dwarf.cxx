#include "dwarf.hxx"
#include "hilldwarf.hxx"
#include <memory>
#include <random>
#include <cstdint>
#include <string>

Dwarf::Dwarf() {}

std::string Dwarf::raceName() { return "Dwarf"; }

std::unique_ptr<Race> Dwarf::generate() {
	static std::default_random_engine engine{static_cast<std::default_random_engine>(std::random_device{}())};
	static std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return std::make_unique<Dwarf>();
		
		case 1:
			return HillDwarf::generate();
	}
	__builtin_unreachable();
}

std::string Dwarf::generateCharacterName() {
	static std::default_random_engine engine{static_cast<std::default_random_engine>(std::random_device{}())};
	static std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return "Gimli";

		case 1:
			return "Gotern";
		}
	__builtin_unreachable();
}
