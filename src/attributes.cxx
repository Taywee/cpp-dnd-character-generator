#include <iostream>
#include <numeric>
#include <random>
#include <cstdint>
#include <array>
#include <algorithm>

int rollAttributes() {
	static std::default_random_engine engine{ static_cast<std::default_random_engine>(std::random_device{}())};
	static std::uniform_int_distribution<> distribution{ 1, 6 };
	
	std::vector<int> results;

	for (int i = 0; i < 4; ++i) {
		results.push_back(distribution(engine));
	}

	std::sort(results.rbegin(), results.rend());
	results.pop_back();
	
	return std::accumulate(results.begin(), results.end(), 0);
}

void setAttributes(std::array<int, 6> &attributes) {
	for (int &attribute : attributes) {
		attribute = rollAttributes();
	}

	std::sort(attributes.rbegin(), attributes.rend());

}
