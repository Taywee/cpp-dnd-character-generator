#include <iostream>
#include "character.hxx"

int main(int argc, char **argv) {

	Character character;
	std::cout << character.getName() << ": " << character.getRace().raceName() << std::endl;
	character.printAttributes(); 
	character.printPhysAttributes();
	character.printRacialFeatures();
	character.printLanguages();
	character.printSpeed();
	
	return 0;
}
