#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "class.hxx"
#include <memory>

class Barbarian : public CharacterClass {

protected:
	std::string c_hitDice { "1d12" };
	std::string c_className {"Barbarian"};
	int c_proficiencyBonus = 2;

public:
	Barbarian(int proficiencyBonus=2, std::string className="Barbarian", std::string hitDice="1d12");

	std::string getClassName() override;
	std::string getSubClass() override;
	void setSkillProficiencies(std::unique_ptr<Race>) override;
	void setArmorProficiencies(std::unique_ptr<Race>) override;
	void setWeaponProficiencies(std::unique_ptr<Race>) override;
	void setToolProficiencies(std::unique_ptr<Race>) override;

	std::unique_ptr<CharacterClass> generate();
};

#endif
