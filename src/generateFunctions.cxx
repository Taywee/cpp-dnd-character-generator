#include <bits/stdint-uintn.h>
#include <iostream>
#include <stdexcept>
#include <map>
#include <random>
#include <fstream>
#include <cstdint>
#include <vector>
#include "json.hpp"

using namespace nlohmann;

void addProficiencies(
		std::vector<std::string> r_proficiencies, 
		std::vector<std::string> m_proficiencies) { 

	for (std::string &proficiency : r_proficiencies) {
		m_proficiencies.push_back(proficiency);
	}
}

std::string generateAlignment() {
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	
	std::uniform_int_distribution<uint8_t> distribution {
		0, static_cast<unsigned char>((tables["alignment"]).size()-1)
	};

	return tables["alignment"][distribution(engine)];
}

std::string generateGender() {
	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<unsigned int> distribution {0, 1};

	switch (distribution(engine)) {
	
		case 0:
			return std::string {"male"};
		case 1:
			return std::string {"female"};
		default:
			throw std::runtime_error("UNREACHABLE");

	}
}

std::map<std::string, int> generateAppearance(std::string race) {
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;
	std::map<std::string, int> attributes;

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	std::uniform_int_distribution<unsigned int> ageDistribution{ 
		tables[race]["age"]["min"], 
		tables[race]["age"]["max"]
	};

	std::normal_distribution<double> heightDistribution{
		tables[race]["height"]["mean"],
		tables[race]["height"]["deviation"]
	};

	std::normal_distribution<double> weightDistribution{
		tables[race]["weight"]["mean"],
		tables[race]["weight"]["deviation"]
	};

	attributes.insert({"Age", static_cast<int>(ageDistribution(engine))});
	attributes.insert({"Height", static_cast<int>(heightDistribution(engine))});
	attributes.insert({"Weight", static_cast<int>(weightDistribution(engine))});

	return attributes;
}

std::string generateCharacterName(std::string race, std::string gender) {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>((tables[race]["names"][gender]).size()-1)
	};

	return tables[race]["names"][gender][distribution(engine)];

	}
