#include "quick_sort.h"
#include "quick_sort_median.h"
#include "quick_sort_final.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

int main(const int argc, char* argv[])
{
	/*
	 * Reading command line arguments and data from input file
	 */

	//Require just one argument.
	//Exit and print error if this is not the case.
	if (argc != 2)
	{
		std::cout << "This function requires one input." << std::endl;
		std::cout << "Example of use:" << std::endl;
		std::cout << argv[0] << " test0.txt <input text file for test>" << std::endl;

		return EXIT_FAILURE;
	}

	int arr_input[MAX_QS_ARRAY_SIZE];
	int arr_input_reset[MAX_QS_ARRAY_SIZE];
	size_t arr_length{0};
	std::string filename_test_file;
	//Get test case filename from argument
	filename_test_file = argv[1];
	//Open test case file
	std::ifstream test_case_file(filename_test_file);
	//Unable to open test case file
	if (!test_case_file.is_open())
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}
	//Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	std::string str_input;
	while (std::getline(test_case_file, str_input))
	{
		arr_input[arr_length++] = stoi(str_input);
	}
	std::cout << "size of file = " << arr_length << std::endl;
	test_case_file.close();

	/*
	 * Running Algorithms
	 */

	std::vector<std::shared_ptr<quick_sort>> qs_list;
	std::vector<size_t> number_compares_qs;
	std::vector<bool> flag_sorted_qs;
	std::vector<std::string> qs_type;

	qs_list.push_back(std::make_shared<quick_sort>());
	qs_type.emplace_back("Quick Sort");
	qs_list.push_back(std::make_shared<quick_sort_final>());
	qs_type.emplace_back("Quick Sort Final");
	qs_list.push_back(std::make_shared<quick_sort_median>());
	qs_type.emplace_back("Quick Sort Median");

	for (const auto& qs : qs_list)
	{
		for (int i = 0; i < arr_length; i++)
		{
			arr_input_reset[i] = arr_input[i];
		}
		qs->sort(arr_input_reset, 0, arr_length - 1);
		number_compares_qs.push_back(qs->get_number_compares());
		flag_sorted_qs.push_back(std::is_sorted(arr_input_reset, arr_input_reset + arr_length - 1));
	}
	
	/*
	 * Output results
	 */

	//Open output file to write the results to file
	const std::string file_output_sorted = "test_case_result.txt";
	std::ofstream test_sorted_file{ file_output_sorted };
	if (test_sorted_file.is_open())
	{
		for (size_t i = 0; i < arr_length; i++)
			test_sorted_file << arr_input_reset[i] << std::endl;
	}
	else
	{
		std::cerr << "Unable to open test case result file" << std::endl;
	}
	test_sorted_file.close();

	//Open output file to write number of comparisons to file
	const std::string file_output_result = "test_case_number_compares.txt";
	std::ofstream test_result_file{ file_output_result };
	if (test_result_file.is_open())
	{
		for (int i = 0; i < qs_list.size(); i++)
		{
			test_result_file << qs_type[i] << " Algo:" << number_compares_qs[i] << std::endl;
			if(!flag_sorted_qs[i])
			{
				test_result_file << "[SORTING ERROR] " << qs_type[i] << std::endl;
			}
			test_result_file << std::endl;
		}
	}
	else
	{
		std::cerr << "Unable to open test case result file" << std::endl;
	}
	test_result_file.close();

	return EXIT_SUCCESS;

}
