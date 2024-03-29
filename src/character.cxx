#include "character.hxx"
#include "attributes.hxx"
#include "generateFunctions.hxx"
#include "races/race.hxx"
#include <iostream>
#include <memory>
#include <random>
#include <cstdint>

Character::Character() {
	setAttributes(m_attributes);
	m_race = Race::generate(proficiencies); 
	m_gender = generateGender();
	m_name = generateCharacterName(m_race->parentRace(), m_gender);
	m_alignment = generateAlignment();
	m_appearance = generateAppearance(m_race->parentRace());
	m_speed = m_race->getSpeed();
	m_languages = m_race->r_languages;
	m_racialFeatures= m_race->r_racialFeatures;
	m_cantrips = m_race->r_cantrips;	
}

void Character::printSpeed() { 
	std::cout << "Speed: " << m_speed << '\n';
}

void Character::printCantrips() {
	std::cout << "Cantrips: ";
	for (auto& cantrip : m_cantrips) {
		std::cout << cantrip << ", ";
	}
std::cout << '\n';
}

void Character::printSpells() {
	std::cout << "Spells: ";
	for (auto& spell : m_spells) {
		std::cout << spell << ", ";
	}
std::cout << '\n';
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
    std::string last_category;
    bool first_proficiency = true;
    for (const auto &proficiency: proficiencies) {
        // The category has changed 
        if (proficiency.category() != last_category) {
            // If the last_category isn't enmpty, we need a newline, because we're not on the first category.
            if (!last_category.empty()) {
                std::cout << '\n';
            }
            last_category = proficiency.category();
            std::cout << last_category << " proficiencies: ";
            first_proficiency = true;
        }
        // Print a comma before every non-first proficiency to have a properly comma-separated list.
        if (!first_proficiency) {
            std::cout << ", ";
        }
        std::cout << proficiency.name();
        first_proficiency = false;
    }
    std::cout << '\n';
}

std::string Character::getName() { return m_name; }
std::string Character::getGender() { return m_gender; }
std::string Character::getAlignment() { return m_alignment; }
const Race &Character::getRace() const { return *m_race; }
Race &Character::getRace() { return *m_race; }
