#ifndef TABLES_H
#define TABLES_H

#include <vector>
#include <string>
#include <map>

namespace tables { 




static const std::vector<std::string> allignments {
	"Lawful Good",
	"Neutral Good",
	"Chaotic Good",
	"Lawful Neutral",
	"Neutral",
	"Chaotic Neutral",
	"Lawful Evil",
	"Neutral Evil",
	"Chaotic Evil"
};

static const std::vector<std::string> sexes { "Male", "Female" };

static const std::vector<std::string> dwarf_names { 
	"Grog", 
	"Forp", 
	"Pip", 
	"Winkle", 
	"Plop", 
	"Gimli", 
	"Balin" };

static std::map<std::string, double> dwarf_physical_att { 
	{"height min", 122}, 
	{"height max", 152},
	{"height mean", 137},
	{"height deviation", 7},

	{"weight min", 100},
	{"weight max", 200},
	{"weight mean", 150},
	{"weight deviation", 10},

	{"age max", 350}};

static std::vector<std::string> dwarf_features {
	"Darkvision",
	"Dwarven Combat Training",
	"Stonecunning"
	};

static std::vector<std::string> dwarf_weapon_proficiencies {
	"battle axe",
	"hand axe",
	"light hammer",
	"warhammer"
	};

static std::vector<std::string> dwarf_tool_proficiencies {
	"smith's tools",
	"brewer's supplies",
	"mason tools"
	};
};

#endif
