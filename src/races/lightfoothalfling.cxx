#include "lightfoothalfling.hxx"
#include "halfling.hxx"
#include "../generateFunctions.hxx"
#include "../json.hpp"
#include "race.hxx"

#include <string>
#include <fstream>
#include <vector>
#include <memory>

using namespace nlohmann;

LightfootHalfling::LightfootHalfling(int speed, std::string race, std::string parent) :
	Halfling::Halfling(),
	r_speed { speed },
	r_raceName { race },
	r_parentRace { parent }
{
	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	for (std::string feature : tables[r_raceName]["features"])
		r_racialFeatures.push_back(feature);
}

int LightfootHalfling::getSpeed() { return r_speed; }
std::string LightfootHalfling::raceName() { return r_raceName; }
std::string LightfootHalfling::parentRace() { return r_parentRace; }
std::unique_ptr<Race> LightfootHalfling::generate(Proficiencies &proficiencies) {
	return std::make_unique<LightfootHalfling>();
}
