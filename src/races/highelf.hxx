#ifndef HIGHELF_H
#define HIGHELF_H

#include "elf.hxx"
#include <memory>
#include <string>

class HighElf : public Elf {

private:
	std::string r_raceName{ "HighElf" };
	std::string r_parentRace{ "Elf" };

public:
	HighElf(std::string race="HighElf", std::string parent="Elf");

	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate(Proficiencies &proficiencies);
};
#endif
