#ifndef LIGHTFOOTHALFLING_H
#define LIGHTFOOTHALFLING_H

#include "halfling.hxx"
#include "race.hxx"
#include <memory>

class LightfootHalfling : public Halfling {

private:
	int r_speed { 25 };
	std::string r_raceName { "Lightfoot Halfling" };
	std::string r_parentRace { "Halfling" };

public:
	LightfootHalfling(int speed=25, std::string race="Lightfoot Halfling", std::string parent="Halfling");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();
};

#endif
