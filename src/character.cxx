#include "character.hxx"
#include "attributes.hxx"
#include <iostream>
#include <memory>
#include <random>
#include <cstdint>

Character::Character() {
	setAttributes(m_attributes);
	m_race = Race::generate(); 
	m_name = m_race->generateCharacterName();

}

Character::Character(std::unique_ptr<Race> race, std::string name) : m_race(std::move(race)), m_name(std::move(name)) {}

void Character::getAttributes() {
	for (int attribute : m_attributes) {
		std::cout << attribute << ' ';
	}
	 std::cout << '\n';
}
std::string Character::getName() { return m_name; }
const Race &Character::getRace() const { return *m_race; }
Race &Character::getRace() { return *m_race; }
