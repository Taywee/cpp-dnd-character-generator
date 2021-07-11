#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "randomfunctions.hpp"

class Character {

private:
	std::string m_name;
	std::string m_allignment;
	std::string m_sex;

	int m_age{};
	double m_height{};
	double m_weight{};

protected:
	Character(
		const std::string& name,
		const std::string& allignment,
		const std::string& sex,

		const int age,
		const double height,
		const double weight); 

public:
	std::string getName() const { return m_name; }
	std::string getAllignment() const { return m_allignment; }
	std::string getSex() const { return m_sex; }

	int getAge() const { return m_age; }
	double getHeight() const { return m_height; }
	double getWeight() const { return m_weight; }

	virtual ~Character() = default;

};

#endif
