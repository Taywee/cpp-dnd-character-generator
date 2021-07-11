#include <iostream>
#include <string>
#include "character.hpp"

Character::Character(
		const std::string& name,
		const std::string& allignment,
		const std::string& sex,
		const int age,
		const double height,
		const double weight) :
	m_name{ name },
	m_allignment{ allignment },
	m_sex{ sex },
	m_age{ age },
	m_height{ height },
	m_weight{ weight } {}

