#include "hilldwarf.hxx"
#include <memory>
#include <string>

HillDwarf::HillDwarf() {}

std::string HillDwarf::raceName() { return "HillDwarf"; }

std::unique_ptr<Race> HillDwarf::generate() {
		return std::make_unique<HillDwarf>();
	}
