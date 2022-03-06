#include "karatsuba_multiplication.h"

#include <cstdlib>
#include <fstream>
#include <iostream>


int main(int argc, char* argv[])
{
	//Require just one argument.
	//Exit and print error if this is not the case.
	if(argc!=2)
	{
		std::cout << "This function requires two inputs." << std::endl;
		std::cout << "Example of use:" << std::endl;
		std::cout << argv[0] << "test0.txt <input text file for test>" << std::endl;

		return EXIT_FAILURE;
	}


	std::string number_1;
	std::string number_2;

	//Get test case filename from argument
	const std::string filename_test_file = argv[1];
	//Open test case file
	std::ifstream test_case_file{ filename_test_file };
	//Unable to open test case file
	if(!test_case_file)
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		test_case_file >> number_1 >> number_2;
	}
	test_case_file.close();

	karatsuba_multiplication km_instance;
	const std::string result = km_instance.multiply(number_1, number_2);

	//Open output file to write the results to file
	const std::string file_output = "test_case_result.txt";
	std::ofstream test_result_file{ file_output };
	if(test_result_file.is_open())
	{
		test_result_file << result;
	}
	else
	{
		std::cerr << "Unable to open test case result file" << std::endl;
	}
	test_result_file.close();	

	return EXIT_SUCCESS;
}