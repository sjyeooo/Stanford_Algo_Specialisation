#include "quick_sort.h"
#include "quick_sort_median.h"
#include "quick_sort_final.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

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
	int arr_input_qsf[MAX_QS_ARRAY_SIZE];
	int arr_input_qsm[MAX_QS_ARRAY_SIZE];
	size_t arr_length = 0;
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

	//Copy input array for quick_sort_median
	for (int i = 0; i < arr_length; i++)
	{
		arr_input_qsf[i] = arr_input[i];
		arr_input_qsm[i] = arr_input[i];
	}

	/*
	 * Running Algorithms
	 */

	//Quick Sort Algo
	quick_sort qs_instance;
	qs_instance.sort(arr_input, 0, arr_length - 1);
	size_t number_compares_qs = qs_instance.get_number_compares();

	//Quick Sort Algo using final element to choose pivot
	quick_sort_final qsf_instance;
	qsf_instance.sort(arr_input_qsf, 0, arr_length - 1);
	size_t number_compares_qsf = qsf_instance.get_number_compares();

	//Quick Sort Algo using median to choose pivot
	quick_sort_median qsm_instance;
	qsm_instance.sort(arr_input_qsm, 0, arr_length - 1);
	size_t number_compares_qsm = qsm_instance.get_number_compares();
	
	/*
	 * Output results
	 */

	//Check if array is sorted
	bool flag_sorted_qs = std::is_sorted(arr_input, arr_input + arr_length - 1);
	bool flag_sorted_qsf = std::is_sorted(arr_input_qsf, arr_input_qsf + arr_length - 1);
	bool flag_sorted_qsm = std::is_sorted(arr_input_qsm, arr_input_qsm + arr_length - 1);

	//Open output file to write the results to file
	const std::string file_output_sorted = "test_case_result.txt";
	std::ofstream test_sorted_file{ file_output_sorted };
	if (test_sorted_file.is_open())
	{
		for (size_t i = 0; i < arr_length; i++)
			test_sorted_file << arr_input[i] << std::endl;
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
		//Output for quick sort quick sort algo
		test_result_file << "Quick Sort Algo:" << number_compares_qs << std::endl;
		if (!flag_sorted_qs)
			test_result_file << "SORTING ERROR FOR QUICK SORT" << std::endl;

		test_result_file << std::endl;

		//Output for quick sort quick sort final algo
		test_result_file << "Quick Sort Final Algo:" << number_compares_qsf << std::endl;
		if (!flag_sorted_qsf)
			test_result_file << "SORTING ERROR FOR QUICK SORT FINAL ALGO" << std::endl;

		test_result_file << std::endl;

		//Output for quick sort quick sort median algo
		test_result_file << "Quick Sort Median Algo:" << number_compares_qsm << std::endl;
		if (!flag_sorted_qsm)
			test_result_file << "SORTING ERROR FOR QUICK SORT MEDIAN ALGO" << std::endl;
	}
	else
	{
		std::cerr << "Unable to open test case result file" << std::endl;
	}
	test_result_file.close();

	return EXIT_SUCCESS;

}
