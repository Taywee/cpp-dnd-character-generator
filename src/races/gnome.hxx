#ifndef GNOME_H 
#define GNOME_H

#include <memory>
#include <string>
#include "race.hxx"

class Gnome : public Race {

private:
	int r_speed = 25;
	std::string r_raceName{ "Gnome" };
	std::string r_parentRace{ "Gnome" };

public:
	Gnome(int speed=25, std::string race="Gnome", std::string parent="Gnome");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);

};

#endif
