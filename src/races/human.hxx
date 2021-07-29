#ifndef HUMAN_H
#define HUMAN_H

#include "race.hxx"
#include <memory>
#include <string>

class Human : public Race {

private:
	int r_speed = 30;
	std::string r_raceName { "Human" };
	std::string r_parentRace { "Human" };

public:
	Human(int speed=30, std::string race="Human", std::string parent="Human");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);

};

#endif
