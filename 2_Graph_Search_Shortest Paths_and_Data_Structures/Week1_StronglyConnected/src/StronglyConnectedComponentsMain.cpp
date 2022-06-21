#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>

#include "ngraph.hpp"
#include "strongly_connected_components.h"

int main(int argc, char *argv[])
{
	// Require just one argument.
	// Exit and print error if this is not the case.
	if (argc != 2)
	{
		// std::cout << "This function requires two inputs." << std::endl;
		// std::cout << "Example of use:" << std::endl;
		// std::cout << argv[0] << " test0.txt <input text file for test>" << std::endl;

		// return EXIT_FAILURE;
	}

	// Get test case filename from argument
	std::string filename_test_file{argv[1]};
	// Open test case file
	std::ifstream test_case_file(filename_test_file);
	// Unable to open test case file
	if (!test_case_file.is_open())
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}

	std::shared_ptr<NGraph::tGraph<size_t>> graph = std::make_shared<NGraph::tGraph<size_t>>();
	std::shared_ptr<NGraph::tGraph<size_t>> graph_reverse = std::make_shared<NGraph::tGraph<size_t>>();

	// Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	std::string str_input;
	unsigned int vertex_src{0};
	unsigned int vertex_dest{0};
	while (test_case_file >> vertex_src >> vertex_dest)
	{
		const int shift = 1;
		graph->insert_edge(vertex_src - shift, vertex_dest - shift);
		graph_reverse->insert_edge(vertex_dest - shift, vertex_src - shift);
	}
	// Print out graph stats (number of vertices and edges)
	graph->print_stats();

	std::shared_ptr<strongly_connected_components> scc =
		std::make_shared<strongly_connected_components>(graph, graph_reverse);
	// Run SCC algo
	scc->run();

	std::vector<size_t> scc_sizes_sorted = scc->get_scc_sizes();
	std::sort(scc_sizes_sorted.begin(), scc_sizes_sorted.end(), std::greater<>());
	std::cout << std::endl << "SCC sizes in descending order:" << std::endl;
	for (unsigned int i = 0; i < 10; i++)
	{
		std::cout << scc_sizes_sorted.at(i) << std::endl;
	}

	return EXIT_SUCCESS;
}