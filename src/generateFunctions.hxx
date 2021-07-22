#ifndef GENERATEAPPEARANCE_H
#define GENERATEAPPEARANCE_H

#include <map>
#include <string>
#include <vector>

void addProficiencies(
		std::vector<std::string> r_proficiencies,
		std::vector<std::string> m_proficiencies);
std::map<std::string, int> generateAppearance(std::string race);
std::string generateGender();
std::string generateAlignment();
std::string generateCharacterName(std::string race, std::string gender);

#endif
