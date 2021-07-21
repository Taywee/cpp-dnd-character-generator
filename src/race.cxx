#include "race.hxx"
#include "dwarf.hxx"
#include "human.hxx"

#include <memory>
#include <random>
#include <cstdint>

Race::~Race() {}

std::unique_ptr<Race> Race::generate() {
	
	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	static std::uniform_int_distribution<std::uint8_t> distribution{ 0, 1 };

	switch (distribution(engine)) {
		case 0:
			return Human::generate();
		case 1:
			return Dwarf::generate();
	}
	__builtin_unreachable();

}
