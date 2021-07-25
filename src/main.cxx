#include <iostream>
#include "character.hxx"

int main(int argc, char **argv) {

	Character character;
	std::cout << character.getName() << ": " << character.getRace().raceName() << '\n';
	std::cout << "gender: " << character.getGender() << '\n';
	std::cout << "alignment: " << character.getAlignment() << '\n';
	character.printAttributes(); 
	character.printPhysAttributes();
	character.printRacialFeatures();
	character.printLanguages();
	character.printSpeed();
	character.printProficiencies();
	character.printCantrips();
	
	return 0;
}
