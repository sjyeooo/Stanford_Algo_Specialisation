#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

#include "completion_times.h"

auto main(int argc, char *argv[]) -> int
{
	const clock_t begin_time = clock();

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

	// Define std::vector containing data
	std::vector<jobs_type> jobs;

	// Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	int64_t num_jobs{1};
	test_case_file >> num_jobs;
	jobs.reserve(num_jobs);
	int32_t input_weight{0}, input_length{0};
	while (test_case_file >> input_weight >> input_length) // Reading each line
	{
		jobs.emplace_back(jobs_type(input_weight, input_length));
	}
	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Inserting into Vector" << std::endl;

	// Sort according to algo 1 (difference between weight and length, with weight as tie breaker)
	std::sort(jobs.begin(), jobs.end(), comp_algo_1);
	int64_t algo_1_result = compute_weighted_result(jobs);

	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Algo 1" << std::endl;

	std::cout << "algo 1 result = " << algo_1_result << std::endl;

	// Sort according to algo 2 (ratio of weight to length)
	std::sort(jobs.begin(), jobs.end(), comp_algo_2);
	int64_t algo_2_result = compute_weighted_result(jobs);

	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Algo 2" << std::endl;

	std::cout << "algo 2 result = " << algo_2_result << std::endl;
}