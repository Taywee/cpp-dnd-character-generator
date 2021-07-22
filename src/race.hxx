#ifndef RACE_H
#define RACE_H

#include <string>
#include <memory>
#include <vector>

class Race { 

public:
	virtual int getSpeed() = 0;
	virtual std::string raceName() = 0;
	virtual std::string generateCharacterName() = 0;
	virtual std::vector<std::string> generateLanguages() = 0;
	virtual std::vector<std::string> generateRacialFeatures() = 0;
	virtual ~Race() = 0;

	static std::unique_ptr<Race> generate();
};

#endif
