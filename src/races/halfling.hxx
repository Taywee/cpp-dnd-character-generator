#ifndef HALFLING_H
#define HALFLING_H

#include "race.hxx"
#include <memory>
#include <string>

class Halfling : public Race {

private:
	int r_speed { 25 };
	std::string r_raceName { "Halfling" };
	std::string r_parentRace { "Halfling" };

public:
	Halfling(int speed=25, std::string race="Halfling", std::string parent="Halfling");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();

};

#endif
