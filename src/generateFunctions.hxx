#ifndef GNERATEFUNCTIONS_H 
#define GNERATEFUNCTIONS_H 

#include <map>
#include <string>
#include <vector>

std::map<std::string, int> generateAppearance(std::string race);
std::vector<std::string> generateData(std::string parentRace, std::string category);
std::string generateGender();
std::string generateAlignment();
std::string generateCharacterName(std::string race, std::string gender);

#endif
