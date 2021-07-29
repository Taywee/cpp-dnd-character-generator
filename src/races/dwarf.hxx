#ifndef DWARF_H
#define DWARF_H

#include <string>
#include <memory>
#include "race.hxx"

class Dwarf : public Race {

private:
	static constexpr int r_speed = 25;	
	static constexpr auto r_raceName { "Dwarf" };
	static constexpr auto r_parentRace { "Dwarf" };

public:
	Dwarf(Proficiencies &proficiencies);
	
	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);

};

#endif
