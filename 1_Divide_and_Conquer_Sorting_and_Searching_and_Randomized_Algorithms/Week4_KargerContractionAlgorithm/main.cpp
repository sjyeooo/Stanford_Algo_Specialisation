#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "disjoint_set.h"
#include "graph_edge_list.h"


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

	//Initialise graph class
	graph_edge_list graph;

	//Able to open test case file
	std::cout << "Opened " << filename_test_file << std::endl;
	std::string str_input;
	while (std::getline(test_case_file, str_input))
	{
		std::istringstream iss(str_input);
		size_t curr_vertex_src = 0;
		iss >> curr_vertex_src;
		size_t curr_vertex_dest = 0;
		while (iss >> curr_vertex_dest)
		{
			//Prevent counting of edges that are already previously defined
			if (curr_vertex_dest > curr_vertex_src)
			{
				//Input file starts from 1, index for the vertex in graph class starts from 0
				graph.add_edge(curr_vertex_src - 1, curr_vertex_dest - 1);
			}
		}
	}
	//Print out graph stats (number of vertices and edges)
	graph.print_graph_stats();

	//Run karger's algorithm
	constexpr size_t num_run_karger_algo = 10000;
	size_t min_contractions = UINTMAX_MAX;
	srand(time(nullptr));
	for (size_t i = 0; i < num_run_karger_algo; i++)
	{
		/*
		 * Run karger algorithm
		 */

		 //Intiialise union find data structure
		disjoint_set uf(graph.vertices());

		//Number of unique vertices
		size_t unique_vertices = graph.vertices();

		while (unique_vertices > 2)
		{
			//(1) Pick an edge at random
			const size_t i_edge_chosen = (rand() % graph.edges());
			edge edge_chosen = graph.get_edge(i_edge_chosen);
			//(2) Combine the two nodes if the nodes are not previously connected
			if (!uf.is_connected(edge_chosen.src(), edge_chosen.dest()))
			{
				uf.Union(edge_chosen.src(), edge_chosen.dest());
				unique_vertices--;
			}
		}

		//(3) With 2 unique vertices left, count number of edges connecting the two unique vertices
		size_t num_edges_cut = 0;
		for (size_t j = 0; j < graph.edges(); j++)
		{
			edge curr_edge = graph.get_edge(j);
			if (!uf.is_connected(curr_edge.src(), curr_edge.dest()))
			{
				num_edges_cut++;
			}
		}
		std::cout << "RUN " << i << " = " << num_edges_cut << std::endl;

		//Update min_contractions
		min_contractions = std::min(min_contractions, num_edges_cut);
	}
	std::cout << "Minimum Contractions = " << min_contractions << std::endl;

	return EXIT_SUCCESS;
}
