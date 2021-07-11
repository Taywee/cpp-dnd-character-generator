#ifndef DWARF_HPP
#define DWARF_HPP

#include "character.hpp"
#include "randomfunctions.hpp"
#include "tables.hpp"
#include <vector>

class Dwarf : public Character {

private:
	const std::string m_race_name{ "Dwarf" };
	const int m_speed{ 25 };
	std::vector<std::string> m_racial_features;
	std::vector<std::string> m_weapon_proficiencies;
	std::vector<std::string> m_tool_proficiencies;

public:
	Dwarf(std::string race="Dwarf", int speed=25); 
	~Dwarf() = default;
	int getSpeed() const { return m_speed; }
	std::string getRace() const { return m_race_name; }
	void getRacialFeatures() const;
	void getWeaponProficiencies() const;
	void getToolProficiencies() const;

};
#endif
