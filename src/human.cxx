#include "human.hxx"
#include "character.hxx"
#include <memory>
#include <random>
#include <cstdint>
#include <string>

Human::Human() {}

std::string Human::raceName() { return "Human"; }

std::unique_ptr<Race> Human::generate() {
	return std::make_unique<Human>();
}

std::string Human::generateCharacterName() {

	static std::default_random_engine engine{static_cast<std::default_random_engine::result_type>(std::random_device{}())};
	static std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return "Adam";

		case 1:
			return "Eve";

	}
	__builtin_unreachable();
}
