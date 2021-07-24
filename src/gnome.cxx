#include "gnome.hxx"
#include "rockgnome.hxx"
#include "race.hxx"
#include "json.hpp"
#include "generateFunctions.hxx"
#include <memory>
#include <random>
#include <cstdint>
#include <stdexcept>

Gnome::Gnome(int speed, std::string race, std::string parent) :
	r_speed { speed },
	r_raceName { race },
	r_parentRace{ parent }
{
	r_racialFeatures = generateData(r_raceName, "features");
	r_languages = generateData(r_raceName, "languages");
}

std::unique_ptr<Race> Gnome::generate() {

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<std::uint8_t> distribution{0, 1};

	switch (distribution(engine)) {
		case 0:
			return std::make_unique<Gnome>();

		case 1:
			return RockGnome::generate();

		default:
			throw std::runtime_error("UNREACHABLE");
	}
}

int Gnome::getSpeed() { return r_speed; }
std::string Gnome::raceName() { return r_raceName; }
std::string Gnome::parentRace() { return r_parentRace; }
