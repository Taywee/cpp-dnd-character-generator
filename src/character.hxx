#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include "races/race.hxx"

class Character {

private:
	std::unique_ptr<Race> m_race;
	std::string m_name;
	std::string m_alignment;
	std::string m_gender;
	std::map<std::string, int> m_appearance;
	std::array<int, 6> m_attributes;
	std::vector<std::string> m_languages;
	std::vector<std::string> m_racialFeatures;
	std::vector<std::string> m_skillProficiencies;
	std::vector<std::string> m_toolProficiencies;
	std::vector<std::string> m_armorProficiencies;
	std::vector<std::string> m_weaponProficiencies;
	std::vector<std::string> m_cantrips;
	std::vector<std::string> m_spells;

	int m_speed;

public:
	Character();

	void printSpeed();
	void printAttributes();
	void printLanguages();
	void printPhysAttributes();
	void printRacialFeatures();
	void printProficiencies();
	void printCantrips();
	void printSpells();
	std::string getName();
	std::string getGender();
	std::string getAlignment();
	const Race &getRace() const;
	Race &getRace();

};
#endif
