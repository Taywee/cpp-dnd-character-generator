#include <iostream>
#include <string>
#include <vector>
#include "dwarf.hpp"
#include "character.hpp"
#include "randomfunctions.hpp"
#include "tables.hpp"

Dwarf::Dwarf(std::string race, int speed) :
	m_racial_features{tables::dwarf_features},
	m_weapon_proficiencies{tables::dwarf_weapon_proficiencies},
	m_tool_proficiencies{getRandomString(
			tables::dwarf_tool_proficiencies)},

	Character::Character{ 
		getRandomString(tables::dwarf_names),
		getRandomString(tables::allignments),
		getRandomString(tables::sexes),
		getRandomInt(350),
		getRandomDouble(
				tables::dwarf_physical_att.at("height mean"),
				tables::dwarf_physical_att.at("height deviation")),
		getRandomDouble(
				tables::dwarf_physical_att.at("weight mean"),
				tables::dwarf_physical_att.at("weight deviation"))}{}

void Dwarf::getRacialFeatures() const {
	for (std::string feature : m_racial_features)	{
		std::cout << feature << " ";
	}
	std::cout << '\n';
}

void Dwarf::getWeaponProficiencies() const {
	for (std::string proficiency : m_weapon_proficiencies)	{
		std::cout << proficiency << " ";
	}
	std::cout << '\n';
}

void Dwarf::getToolProficiencies() const {
	for (std::string proficiency : m_tool_proficiencies)	{
		std::cout << proficiency << " ";
	}
	std::cout << '\n';
}
