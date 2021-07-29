#ifndef ROCKGNOME_H 
#define ROCKGNOME_H 

#include "gnome.hxx"
#include <memory>
#include <string>

class RockGnome : public Gnome {

private:
	std::string r_raceName{ "RockGnome" };
	std::string r_parentRace{ "Gnome" };

public:
	RockGnome(std::string race="RockGnome", std::string parent="Gnome");

	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);
};
#endif
