#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include <memory>
#include <string>
#include "race.hxx"

class Character {

private:
	std::unique_ptr<Race> m_race;
	std::string m_name;
	std::array<int, 6> m_attributes;

public:
	Character();

	Character(std::unique_ptr<Race> race, std::string name);

	void getAttributes();
	std::string getName();
	const Race &getRace() const;
	Race &getRace();

};
#endif
