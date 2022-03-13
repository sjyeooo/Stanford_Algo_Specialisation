#include "count_inversion.h"
#include "count_inversion_brute.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	//Require just one argument.
	//Exit and print error if this is not the case.
	if (argc != 2)
	{
		std::cout << "This function requires two inputs." << std::endl;
		std::cout << "Example of use:" << std::endl;
		std::cout << argv[0] << " test0.txt <input text file for test>" << std::endl;

		//return EXIT_FAILURE;
	}

	int arr_input[MAX_INV_ARRAY_SIZE];
	size_t arr_length = 0;

	//Get test case filename from argument
	std::string filename_test_file = argv[1];
	//Open test case file
	std::ifstream test_case_file{ filename_test_file };
	//Unable to open test case file
	if (!test_case_file)
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Opened " << filename_test_file << std::endl;
	while (!test_case_file.eof())
	{
		int current_input;
		test_case_file >> current_input;
		arr_input[arr_length++] = current_input;
	}
	std::cout << "size of file = " << arr_length << std::endl;
	test_case_file.close();

	//Brute Force implementation
	//count_inversion_brute ci_brute_instance;
	//size_t cnt_cib = ci_brute_instance.count(arr_input, arr_length);

	count_inversion ci_instance;
	size_t cnt_ci = ci_instance.count(arr_input, arr_length);

	//Open output file to write the results to file
	const std::string file_output = "test_case_result.txt";
	std::ofstream test_result_file{ file_output };
	if (test_result_file.is_open())
	{
		test_result_file << cnt_ci;
	}
	else
	{
		std::cerr << "Unable to open test case result file" << std::endl;
	}
	test_result_file.close();

	return EXIT_SUCCESS;
}
