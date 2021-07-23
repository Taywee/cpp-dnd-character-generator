#ifndef DWARF_H
#define DWARF_H

#include <string>
#include <memory>
#include <vector>
#include "race.hxx"

class Dwarf : public Race {

private:
	int r_speed = 25;	
	std::string r_raceName { "Dwarf" };
	std::string r_parentRace { "Dwarf" };

public:
	Dwarf(int speed=25, std::string race="Dwarf", std::string parent="Dwarf");
	
	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();
};

#endif
