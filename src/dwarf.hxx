#ifndef DWARF_H
#define DWARF_H

#include <string>
#include <memory>
#include <vector>
#include "race.hxx"

class Dwarf : public Race {

private:
	int r_speed = 25;	
	std::vector<std::string> r_weaponProficiencies;
	std::vector<std::string> r_toolProficiencies;

public:
	Dwarf(int speed=25);
	
	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	std::vector<std::string> generateLanguages() override;
	std::vector<std::string> generateRacialFeatures() override;
	static std::unique_ptr<Race> generate();
};

#endif
