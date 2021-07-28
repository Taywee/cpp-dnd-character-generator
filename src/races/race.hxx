#ifndef RACE_H
#define RACE_H

#include <string>
#include <memory>
#include <vector>

class Race { 

public:
	std::vector<std::string> r_racialFeatures;
	std::vector<std::string> r_languages;
	std::vector<std::string> r_skillProficiencies;
	std::vector<std::string> r_toolProficiencies;
	std::vector<std::string> r_weaponProficiencies;
	std::vector<std::string> r_armorProficiencies;
	std::vector<std::string> r_cantrips; 

	virtual int getSpeed() = 0;
	virtual std::string raceName() = 0;
	virtual std::string parentRace() = 0;
	virtual ~Race() = 0;

	static std::unique_ptr<Race> generate();

};

#endif
