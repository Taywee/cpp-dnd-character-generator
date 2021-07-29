#ifndef TIEFLING_H 
#define TIEFLING_H 

#include "race.hxx"
#include <memory>
#include <string>

class Tiefling : public Race {

private:
	int r_speed = 30;
	std::string r_raceName { "Tiefling" };
	std::string r_parentRace { "Tiefling" };

public:
 Tiefling(int speed=30, std::string race="Tiefling", std::string parent="Tiefling");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);

};

#endif
