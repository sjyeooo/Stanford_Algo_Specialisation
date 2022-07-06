#include <iostream>
#include <string>

#include "median_heap.h"

auto main() -> int
{
	// Create a (uniquely owned) resource for median_heap algo
	const std::unique_ptr<median_heap> median_algo(std::make_unique<median_heap>());

	int medianSum = 0;
	while (std::cin.peek() != EOF)
	{
		std::string input_line;
		// Read whole of first line
		std::getline(std::cin, input_line);
		const int input_val = atoi(input_line.c_str());
		median_algo->push(input_val);
		// Keep track of median sum
		medianSum = (medianSum + median_algo->median()) % 10000;
	}

	std::cout << "Median Sum = " << medianSum << std::endl;
}