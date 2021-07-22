#ifndef HILLDWARF_H 
#define HILLDWARF_H

#include "dwarf.hxx"
#include <memory>
#include <string>
#include <vector>

class HillDwarf : public Dwarf {

public:
	HillDwarf();

	std::string raceName() override;
	std::vector<std::string> generateRacialFeatures() override;
	static std::unique_ptr<Race> generate();
};

#endif
