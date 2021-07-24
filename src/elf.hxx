#ifndef ELF_H
#define ELF_H

#include <memory>
#include <string>
#include "race.hxx"

class Elf : public Race {

private:
	int r_speed = 30;
	std::string r_raceName{ "Elf" };
	std::string r_parentRace{ "Elf" };

public:
	Elf(int speed=30, std::string race="Elf", std::string parent="Elf");

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();

};

#endif
