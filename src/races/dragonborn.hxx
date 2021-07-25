#ifndef DRAGONBORN_H
#define DRAGONBORN_H

#include "race.hxx"
#include <memory>
#include <string>

class Dragonborn : public Race {

private:
	int r_speed = 30;
	std::string r_raceName { "Dragonborn" };
	std::string r_parentRace { "Dragonborn" };

public:
	Dragonborn(int speed=30, std::string race="Dragonborn", std::string parent="Dragonborn");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();

};

#endif
