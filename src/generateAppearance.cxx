#include <iostream>
#include <map>
#include <random>
#include <fstream>
#include <cstdint>
#include "json.hpp"

using namespace nlohmann;

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
