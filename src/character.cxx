#include "character.hxx"
#include "attributes.hxx"
#include "generateFunctions.hxx"
#include "race.hxx"
#include <iostream>
#include <memory>
#include <random>
#include <cstdint>

Character::Character() {
	setAttributes(m_attributes);
	m_race = Race::generate(); 
	m_gender = generateGender();
	m_name = generateCharacterName(m_race->parentRace(), m_gender);
	m_alignment = generateAlignment();
	m_appearance = generateAppearance(m_race->parentRace());
	m_speed = m_race->getSpeed();
	m_languages = m_race->r_languages;
	m_racialFeatures= m_race->r_racialFeatures;
	m_skillProficiencies = m_race->r_skillProficiencies;
	m_armorProficiencies = m_race->r_armorProficiencies;
	m_weaponProficiencies = m_race->r_weaponProficiencies;
	m_toolProficiencies = m_race->r_toolProficiencies;

}

void Character::printSpeed() { 
	std::cout << "Speed: " << m_speed << '\n';
}

void Character::printRacialFeatures() {
	std::cout << "Racial features: ";
	for (auto& feature : m_racialFeatures) {
		std::cout << feature << ", ";
	}
	std::cout << '\n';
}

void Character::printLanguages() {
	std::cout << "Languages: ";
	for (auto& language : m_languages) {
		std::cout << language << ", ";
	}
	std::cout << '\n';
}

void Character::printAttributes() {
	for (int attribute : m_attributes) {
		std::cout << attribute << ' ';
	}
	 std::cout << '\n';
}

void Character::printPhysAttributes() {
	for (auto& [key, value] : m_appearance) {
		std::cout << key << ": " << value << '\n';
	}
	std::cout << '\n';
}

void Character::printProficiencies() {
	std::cout << "Skill proficiencies: ";
	for (std::string proficiency : m_skillProficiencies) {
		std::cout << proficiency << ", ";
	}
	std::cout << '\n';
	std::cout << "Weapon proficiencies: ";
	for (std::string proficiency : m_weaponProficiencies) {
		std::cout << proficiency << ", ";
	}
	std::cout << '\n';
	std::cout << "Armor proficiencies: ";
	for (std::string proficiency : m_armorProficiencies) {
		std::cout << proficiency << ", ";
	}
	std::cout << '\n';
	std::cout << "Tool proficiencies: ";
	for (std::string proficiency : m_toolProficiencies) {
		std::cout << proficiency << ", ";
	}
	std::cout << '\n';
}

std::string Character::getName() { return m_name; }
std::string Character::getGender() { return m_gender; }
std::string Character::getAlignment() { return m_alignment; }
const Race &Character::getRace() const { return *m_race; }
Race &Character::getRace() { return *m_race; }
