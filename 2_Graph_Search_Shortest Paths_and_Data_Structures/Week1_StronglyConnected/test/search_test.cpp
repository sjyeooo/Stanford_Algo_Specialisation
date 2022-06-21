#include <fstream>

#include "../src/breath_first_search.h"
#include "../src/depth_first_search.h"
#include "../src/ngraph.hpp"

int main()
{
	// Define test case filename
	std::string filename_test_file{"../../matlab/small.txt"};
	// Open test case file
	std::ifstream test_case_file(filename_test_file);
	// Unable to open test case file
	if (!test_case_file.is_open())
	{
		std::cout << "Unable to open test case file" << std::endl;
		return EXIT_FAILURE;
	}

	const std::shared_ptr<NGraph::Graph> graph = std::make_shared<NGraph::Graph>();

	// Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	std::string str_input;
	unsigned int vertex_src{0};
	unsigned int vertex_dest{0};
	while (test_case_file >> vertex_src >> vertex_dest)
	{
		graph->insert_edge(vertex_src, vertex_dest);
	}

	// Initialise and run DFS algorithm
	const auto dfs = std::make_unique<depth_first_search>(graph, 1);
	dfs->print_search_path("../../matlab/dfs_result_small.txt");

	// Initialise and run BFS algorithm
	const auto bfs = std::make_unique<breath_first_search>(graph, 1);
	bfs->print_search_path("../../matlab/bfs_result_small.txt");

	return EXIT_SUCCESS;
}
