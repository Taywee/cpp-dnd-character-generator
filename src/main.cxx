#include <iostream>
#include "character.hxx"

int main(int argc, char **argv) {

	Character character;
	std::cout << character.getName() << ": " << character.getRace().raceName() << std::endl;
	character.getAttributes(); 
	std::cout << std::endl;

	return 0;
}
