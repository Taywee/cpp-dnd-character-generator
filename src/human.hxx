#ifndef HUMAN_H
#define HUMAN_H

#include "race.hxx"
#include "character.hxx"
#include <memory>
#include <pthread.h>
#include <string>
#include <vector>

class Human : public Race {

protected:
	int r_speed = 30;
	std::string r_raceName { "Human" };
	std::string r_parentRace { "Human" };

public:
	Human(int speed=30, std::string race="Human", std::string parent="Human");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();

	friend class Character;

};

#endif
