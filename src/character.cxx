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
	m_appearance = generateAppearance(m_race->raceName());
	
}

void Character::getAttributes() {
	for (int attribute : m_attributes) {
		std::cout << attribute << ' ';
	}
	 std::cout << '\n';
}

void Character::getPhysAttributes() {
	for (auto& [key, value] : m_appearance) {
		std::cout << key << ": " << value << '\n';
	}
	std::cout << std::endl;
}

std::string Character::getName() { return m_name; }
const Race &Character::getRace() const { return *m_race; }
Race &Character::getRace() { return *m_race; }
