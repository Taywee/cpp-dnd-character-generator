#ifndef HUMAN_H
#define HUMAN_H

#include "race.hxx"
#include "character.hxx"
#include <memory>
#include <pthread.h>
#include <string>

class Human : public Race {

public:
	Human();

	std::string raceName() override;
	std::string generateCharacterName() override;
	static std::unique_ptr<Race> generate();
};

#endif
