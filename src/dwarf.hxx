#ifndef DWARF_H
#define DWARF_H

#include <string>
#include <memory>
#include "race.hxx"

class Dwarf : public Race {

public:
	Dwarf();
	
	std::string raceName() override;
	std::string generateCharacterName() override;
	static std::unique_ptr<Race> generate();
};

#endif
