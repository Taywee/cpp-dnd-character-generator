#ifndef HILLDWARF_H 
#define HILLDWARF_H

#include "dwarf.hxx"
#include <memory>
#include <string>

class HillDwarf : public Dwarf {

public:
	HillDwarf();

	std::string raceName() override;
	static std::unique_ptr<Race> generate();
};

#endif
