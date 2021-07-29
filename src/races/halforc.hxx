#ifndef HALFORC_H 
#define HALFORC_H 

#include "race.hxx"
#include <memory>
#include <string>

class HalfOrc : public Race {

private:
	int r_speed = 30;
	std::string r_raceName { "HalfOrc" };
	std::string r_parentRace { "HalfOrc" };

public:
 HalfOrc(int speed=30, std::string race="HalfOrc", std::string parent="HalfOrc");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);

};

#endif
