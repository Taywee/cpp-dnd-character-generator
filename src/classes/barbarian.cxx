#include "barbarian.hxx"
#include "class.hxx"
#include "../json.hpp"
#include "../character.hxx"
#include "../generateFunctions.hxx"

#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace nlohmann;

Barbarian::Barbarian(int proficiencyBonus, std::string name, std::string hitDice) :
	c_className { name },
	c_proficiencyBonus { proficiencyBonus },
	c_hitDice { hitDice }
{
	c_savingThrows = generateData(c_className, "saving throws");
	c_classFeatures = generateData(c_className, "features");
	setArmorProficiencies(Character::m_race);
}

void Barbarian::setSkillProficiencies(std::unique_ptr<Race> race) {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> temp_proficiencies;

	for (auto& skill : tables[c_className]["skill proficiencies"]) {
		temp_proficiencies.push_back(skill);
	}

	for (auto newSkill = temp_proficiencies.begin(); 
			newSkill != temp_proficiencies.end(); 
			++newSkill) {
		for (auto currentSkill = race->r_skillProficiencies.begin();
				currentSkill != race->r_skillProficiencies.end();
				++currentSkill) {
			if (newSkill == currentSkill) {
				temp_proficiencies.erase(newSkill);
			}
		}
	}

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>(temp_proficiencies.size()-1)
	};

	std::shuffle(temp_proficiencies.begin(), temp_proficiencies.end(), engine);
	c_skillProficiencies.push_back(temp_proficiencies[0]);
	c_skillProficiencies.push_back(temp_proficiencies[1]);

}

void Barbarian::setArmorProficiencies(std::unique_ptr<Race> race) {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> temp_proficiencies;

	for (auto& skill : tables[c_className]["armor proficiencies"]) {
		temp_proficiencies.push_back(skill);
	}

	for (auto newSkill = temp_proficiencies.begin(); 
			newSkill != temp_proficiencies.end(); 
			++newSkill) {
		for (auto currentSkill = race->r_armorProficiencies.begin();
				currentSkill != race->r_armorProficiencies.end();
				++currentSkill) {
			if (newSkill == currentSkill) {
				temp_proficiencies.erase(newSkill);
			}
		}
	}

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>(temp_proficiencies.size()-1)
	};

	std::shuffle(temp_proficiencies.begin(), temp_proficiencies.end(), engine);
	c_skillProficiencies.push_back(temp_proficiencies[0]);
	c_skillProficiencies.push_back(temp_proficiencies[1]);

}

void Barbarian::setWeaponProficiencies(std::unique_ptr<Race> race) {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> temp_proficiencies;

	for (auto& skill : tables[c_className]["weapon proficiencies"]) {
		temp_proficiencies.push_back(skill);
	}

	for (auto newSkill = temp_proficiencies.begin(); 
			newSkill != temp_proficiencies.end(); 
			++newSkill) {
		for (auto currentSkill = race->r_weaponProficiencies.begin();
				currentSkill != race->r_weaponProficiencies.end();
				++currentSkill) {
			if (newSkill == currentSkill) {
				temp_proficiencies.erase(newSkill);
			}
		}
	}

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>(temp_proficiencies.size()-1)
	};

	std::shuffle(temp_proficiencies.begin(), temp_proficiencies.end(), engine);
	c_skillProficiencies.push_back(temp_proficiencies[0]);
	c_skillProficiencies.push_back(temp_proficiencies[1]);

}

void Barbarian::setToolProficiencies(std::unique_ptr<Race> race) {

	std::ifstream i("../data/tables.json");
	json tables;
	i >> tables;

	std::vector<std::string> temp_proficiencies;

	for (auto& skill : tables[c_className]["tool proficiencies"]) {
		temp_proficiencies.push_back(skill);
	}

	for (auto newSkill = temp_proficiencies.begin(); 
			newSkill != temp_proficiencies.end(); 
			++newSkill) {
		for (auto currentSkill = race->r_toolProficiencies.begin();
				currentSkill != race->r_toolProficiencies.end();
				++currentSkill) {
			if (newSkill == currentSkill) {
				temp_proficiencies.erase(newSkill);
			}
		}
	}

	static std::default_random_engine engine {
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};
	std::uniform_int_distribution<std::uint8_t> distribution {
		0, static_cast<unsigned char>(temp_proficiencies.size()-1)
	};

	std::shuffle(temp_proficiencies.begin(), temp_proficiencies.end(), engine);
	c_skillProficiencies.push_back(temp_proficiencies[0]);
	c_skillProficiencies.push_back(temp_proficiencies[1]);

}
