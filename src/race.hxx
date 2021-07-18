#ifndef RACE_H
#define RACE_H

#include <string>
#include <memory>

class Race { 

public:
	virtual std::string raceName() = 0;
	virtual std::string generateCharacterName() = 0;
	virtual ~Race() = 0;

	static std::unique_ptr<Race> generate();
};

#endif
