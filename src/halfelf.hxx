#ifndef HALFELF_H 
#define HALFELF_H 

#include "race.hxx"
#include <memory>
#include <string>

class HalfElf: public Race {

private:
	int r_speed = 30;
	std::string r_raceName { "HalfElf" };
	std::string r_parentRace { "HalfElf" };

public:
	HalfElf(int speed=30, std::string race="HalfElf", std::string parent="HalfElf");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();

};

#endif
