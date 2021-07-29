#ifndef DRAGONBORN_H
#define DRAGONBORN_H

#include "race.hxx"
#include <memory>
#include <string>

class Dragonborn : public Race {

private:
	static constexpr int r_speed = 30;
	static constexpr auto r_raceName { "Dragonborn" };
	static constexpr auto r_parentRace { "Dragonborn" };

public:
	Dragonborn(Proficiencies &proficiencies);

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);

};

#endif
