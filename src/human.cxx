#include "human.hxx"
#include "json.hpp"
#include "character.hxx"
#include <fstream>
#include <memory>
#include <random>
#include <cstdint>
#include <string>
#include <vector>

using namespace nlohmann;

Human::Human() {}

std::string Human::raceName() { return "Human"; }

std::unique_ptr<Race> Human::generate() {
	return std::make_unique<Human>();
}

std::string Human::generateCharacterName() {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	static std::default_random_engine engine{static_cast<std::default_random_engine::result_type>(std::random_device{}())};
	static std::uniform_int_distribution<std::uint8_t> distribution{
		0, static_cast<unsigned char>((tables["Human"]["maleNames"]).size()-1)
	};

	return tables["Human"]["maleNames"][distribution(engine)];

	}

std::vector<std::string> Human::generateLanguages() {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> langs;
	for (int i = 0; i < static_cast<unsigned char>((tables["human"]["languages"].size())); ++i) {
		langs.push_back(tables["human"]["languages"][i]);
	}

	static std::default_random_engine engine{static_cast<std::default_random_engine::result_type>(std::random_device{}())};
	static std::uniform_int_distribution<std::uint8_t> distribution{0, static_cast<unsigned char>((tables["languages"].size()-1))};

	langs.push_back(tables["languages"][distribution(engine)]);

	return langs;

}
