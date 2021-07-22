#include <iostream>
#include <numeric>
#include <random>
#include <cstdint>
#include <array>
#include <algorithm>

// Function that returns the sum of the results of the 3 highest of 4 d6 rolls
int rollAttributes() {

	static std::default_random_engine engine{ 
		static_cast<std::default_random_engine::result_type>(std::random_device{}())
	};

	static std::uniform_int_distribution<> distribution{ 1, 6 };
	
	std::vector<int> results;

	// Loop to add results from 4d6 rolls
	for (int i = 0; i < 4; ++i) {
		results.push_back(distribution(engine));
	}

	// Reverse sort the results and remove the lowest roll
	std::sort(results.rbegin(), results.rend());
	results.pop_back();
	
	// Return the sum of the three highest rolls
	return std::accumulate(results.begin(), results.end(), 0);
}

void setAttributes(std::array<int, 6> &attributes) {

	// Iterate through the array and call the rollAttributes() function for each element
	for (int &attribute : attributes) {
		attribute = rollAttributes();
	}

	// Reverse sort the array
	std::sort(attributes.rbegin(), attributes.rend());

}
