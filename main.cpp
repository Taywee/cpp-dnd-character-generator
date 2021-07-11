#include "dwarf.hpp"
#include <iostream>

int main() {

	Dwarf character{};

	std::cout << "Name: ";
	std::cout << character.getName() << '\n';
	std::cout << "Race: ";
	std::cout << character.getRace() << '\n';
	std::cout << "Speed: ";
	std::cout << character.getSpeed() << '\n';
	std::cout << "Age: ";
	std::cout << character.getAge() << '\n';
	std::cout << "Allignment: ";
	std::cout << character.getAllignment() << '\n';
	std::cout << "Height: ";
	std::cout << character.getHeight() << '\n';
	std::cout << "Weight: ";
	std::cout << character.getWeight() << '\n';
	std::cout << "Sex: ";
	std::cout << character.getSex() << '\n';
	std::cout << "Racial Features: ";
	character.getRacialFeatures();
	std::cout << "Weapon Proficiencies: ";
	character.getWeaponProficiencies();
	std::cout << "Tool Proficiencies: ";
	character.getToolProficiencies();

	return 0;
}
