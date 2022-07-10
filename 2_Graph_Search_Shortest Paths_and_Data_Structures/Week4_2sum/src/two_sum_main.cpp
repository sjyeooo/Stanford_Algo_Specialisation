#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

#include "two_sum.h"

auto main(int argc, char *argv[]) -> int
{
	const clock_t begin_time = clock();

	// Create a (uniquely owned) resource for two_sum algo
	const std::unique_ptr<two_sum> two_sum_algo(std::make_unique<two_sum>());

	// Require just one argument.
	// Exit and print error if this is not the case.
	if (argc != 2)
	{
		std::cout << "This function requires two inputs." << std::endl;
		std::cout << "Example of use:" << std::endl;
		std::cout << argv[0] << " test0.txt <input text file for test>" << std::endl;

		return EXIT_FAILURE;
	}
	std::string filename_test_file;
	// Get test case filename from argument
	filename_test_file = argv[1];

	// Open test case file
	std::ifstream test_case_file(filename_test_file);
	// Unable to open test case file
	if (!test_case_file.is_open())
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}
	// Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	int64_t input_val{0};
	while (test_case_file >> input_val) // Reading each line
	{
		two_sum_algo->insert(input_val);
	}
	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Inserting into Hash Table" << std::endl;

	std::vector<int64_t> targets(20001);
	std::iota(targets.begin(), targets.end(), -10000);
	const auto answer = two_sum_algo->run(targets);
	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Targets" << std::endl;

	std::cout << "count = " << answer << std::endl;
}