#ifndef HILLDWARF_H 
#define HILLDWARF_H

#include "dwarf.hxx"
#include <memory>
#include <string>
#include <vector>

class HillDwarf : public Dwarf {

private:
	std::string r_raceName{ "HillDwarf" };
	std::string r_parentRace{ "Dwarf" };

public:
	HillDwarf(std::string race="HillDwarf", std::string parent="Dwarf");

	std::string raceName() override;
	std::string parentRace() override;
	static std::unique_ptr<Race> generate();
};

#endif
