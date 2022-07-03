#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>

#include "dijkstra.h"
#include "graph.hpp"

auto main(int argc, char *argv[]) -> int
{
	std::string filename_test_file;
	std::vector<std::ptrdiff_t> target_vertex_of_interest;

	// Require just one argument.
	// Exit and print error if this is not the case.
	if (argc != 2)
	{
		// std::cout << "This function requires two inputs." << std::endl;
		// std::cout << "Example of use:" << std::endl;
		// std::cout << argv[0] << " test0.txt <input text file for test>" << std::endl;

		// return EXIT_FAILURE;
		filename_test_file = "../../dijkstraSmall.txt";
		target_vertex_of_interest = {2, 3, 4};
	}
	else
	{
		std::string temp{argv[1]};
		filename_test_file = temp;
		target_vertex_of_interest = {7, 37, 59, 82, 99, 115, 133, 165, 188, 197};
	}

	// Get test case filename from argument{argv[1]};
	// Open test case file

	std::ifstream test_case_file(filename_test_file);
	// Unable to open test case file
	if (!test_case_file.is_open())
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}

	std::shared_ptr<graph<std::ptrdiff_t, std::size_t>> Graph = std::make_shared<graph<std::ptrdiff_t, std::size_t>>();

	// Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	std::string str_input;
	constexpr std::ptrdiff_t shift{1};
	while (std::getline(test_case_file, str_input)) // Reading each line
	{
		std::istringstream iss(str_input);
		std::ptrdiff_t vertex_src{0};
		std::ptrdiff_t vertex_dest{0};
		std::ptrdiff_t edge_weight{0};
		iss >> vertex_src;
		char comma{','};
		Graph->add_vertex(vertex_src - shift);
		while (iss >> vertex_dest >> comma >> edge_weight)
		{
			if (!Graph->is_vertex_present(vertex_dest - shift))
			{
				Graph->add_vertex(vertex_dest - shift);
			}
			Graph->add_edge(vertex_src - shift, vertex_dest - shift, edge_weight);
		}
	}

	std::shared_ptr<dijkstra> dijkstra_algo = std::make_shared<dijkstra>(Graph, 0);
	for (const auto vertex_interest : target_vertex_of_interest)
	{
		std::cout << dijkstra_algo->dist_to(vertex_interest - shift) << ",";
	}

	return EXIT_SUCCESS;
}