#ifndef HUMAN_H
#define HUMAN_H

#include "race.hxx"
#include "character.hxx"
#include <memory>
#include <pthread.h>
#include <string>
#include <vector>

class Human : public Race {

private:
	int r_speed = 30;

public:
	Human(int speed=30);

	int getSpeed() override;
	std::string raceName() override;
	std::string parentRace() override;
	std::vector<std::string> generateLanguages() override;
	std::vector<std::string> generateRacialFeatures() override;
	static std::unique_ptr<Race> generate();
};

#endif
