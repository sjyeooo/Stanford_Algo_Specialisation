#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "graph.hpp"
#include "prim_mst.hpp"

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

	graph<int32_t, int32_t> graph_data;

	// Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	int64_t num_nodes{1}, num_edges{1};
	test_case_file >> num_nodes >> num_edges;
	int32_t edge_node_1{0}, edge_node_2{0}, edge_cost{0};
	constexpr int32_t shift = -1;
	while (test_case_file >> edge_node_1 >> edge_node_2 >> edge_cost) // Reading each line
	{
		edge_node_1 += shift;
		edge_node_2 += shift;
		// Add vertex if not present
		if (!graph_data.is_vertex_present(edge_node_1))
		{
			graph_data.add_vertex(edge_node_1);
		}
		if (!graph_data.is_vertex_present(edge_node_2))
		{
			graph_data.add_vertex(edge_node_2);
		}
		// Add edge
		graph_data.add_undirected_edge(edge_node_1, edge_node_2, edge_cost);
	}
	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Inserting into Graph" << std::endl;

	const std::unique_ptr<prim_mst<int32_t, int32_t>> prim_algo_ptr(
		std::make_unique<prim_mst<int32_t, int32_t>>(graph_data));

	std::cout << "cost = " << prim_algo_ptr->get_mst_weight() << std::endl;

	std::cout << "elapsed time: " << static_cast<float>(clock() - begin_time) / CLOCKS_PER_SEC << " -- ";
	std::cout << "Completed Prim MST" << std::endl;
}