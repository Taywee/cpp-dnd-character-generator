#include "character.hxx"
#include "attributes.hxx"
#include "generateAppearance.hxx"
#include <iostream>
#include <memory>
#include <random>
#include <cstdint>

Character::Character() {
	setAttributes(m_attributes);
	m_race = Race::generate(); 
	m_name = m_race->generateCharacterName();
	m_languages = m_race->generateLanguages();
	m_racialFeatures = m_race->generateRacialFeatures();
	m_appearance = generateAppearance(m_race->raceName());
	m_speed = m_race->getSpeed();
	
}

void Character::printSpeed() { 
	std::cout << "Speed: " << m_speed << std::endl;
}

void Character::printRacialFeatures() {
	std::cout << "Racial features: ";
	for (auto& feature : m_racialFeatures) {
		std::cout << feature << ", ";
	}
	std::cout << std::endl;
}
void Character::printLanguages() {
	std::cout << "Languages: ";
	for (auto& language : m_languages) {
		std::cout << language << ", ";
	}
	std::cout << std::endl;
}

void Character::printAttributes() {
	for (int attribute : m_attributes) {
		std::cout << attribute << ' ';
	}
	 std::cout << std::endl;
}

void Character::printPhysAttributes() {
	for (auto& [key, value] : m_appearance) {
		std::cout << key << ": " << value << '\n';
	}
	std::cout << std::endl;
}

std::string Character::getName() { return m_name; }
const Race &Character::getRace() const { return *m_race; }
Race &Character::getRace() { return *m_race; }
