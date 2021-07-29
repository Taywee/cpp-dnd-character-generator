#ifndef RACE_H
#define RACE_H

#include <string>
#include <memory>
#include <vector>
#include "../proficiencies.hxx"

class Race { 

public:
	std::vector<std::string> r_racialFeatures;
	std::vector<std::string> r_languages;
	std::vector<std::string> r_cantrips; 

	virtual int getSpeed() = 0;
	virtual std::string raceName() = 0;
	virtual std::string parentRace() = 0;
	virtual ~Race() = 0;

	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);
};

#endif
