#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

#include <memory>
#include <vector>
#include <string>

class Race;
class CharacterClass {

protected:
	std::vector<std::string> c_classFeatures;
	std::vector<std::string> c_skillProficiencies;
	std::vector<std::string> c_armorProficiencies;
	std::vector<std::string> c_weaponProficiencies;
	std::vector<std::string> c_toolProficiencies;
	std::vector<std::string> c_savingThrows;
	std::string c_subClass;

public:
	virtual std::string getClassName() = 0;
	virtual std::string getSubClass() = 0;
	virtual void setSkillProficiencies(std::unique_ptr<Race>) = 0;
	virtual void setArmorProficiencies(std::unique_ptr<Race>) = 0;
	virtual void setWeaponProficiencies(std::unique_ptr<Race>) = 0;
	virtual void setToolProficiencies(std::unique_ptr<Race>) = 0;
	virtual ~CharacterClass();

	static std::unique_ptr<CharacterClass> generate();

	friend class Character;
};

#endif
