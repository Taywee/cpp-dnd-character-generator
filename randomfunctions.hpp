#ifndef RANDOMFUNCTIONS_H
#define RANDOMFUNCTIONS_H 

#include <random>
#include <iostream>
#include <string>
#include <vector>

static std::random_device random_device{};
static std::mt19937 random_engine{random_device()};

static std::string getRandomString(const std::vector<std::string> &choices) {
	std::uniform_int_distribution<int> dist(0, choices.size() - 1);
	return choices[dist(random_engine)];
}

static double getRandomDouble(double mean, double dev) {
	std::normal_distribution<>	dist{mean, dev};
	return std::round(dist(random_engine));
}

static int getRandomInt(const int max) {
	std::uniform_int_distribution<int> dist(18, max);
	return dist(random_engine);
}



#endif
