#include "depth_first_search.h"

#include <fstream>

depth_first_search::depth_first_search()
{
}

depth_first_search::depth_first_search(std::shared_ptr<NGraph::Graph> g, int src) :
	g_(g),
	marked_(g->num_vertices(), false),
	edge_to_(g->num_vertices(), 0)
{
	dfs(src);
}

depth_first_search::~depth_first_search()
{
}

void depth_first_search::print_search_path(std::string filename)
{
	std::ofstream file_output(filename);
	std::queue<unsigned int> temp_queue = search_path_;

	while (!temp_queue.empty())
	{
		file_output << temp_queue.front() << std::endl;
		temp_queue.pop();
	}
}

void depth_first_search::dfs(unsigned int v)
{
	marked_[v] = true;
	search_path_.push(v);

	for (const unsigned int w : g_->out_neighbors(v))
	{
		if (!marked_[w])
		{
			dfs(w);
			edge_to_[w] = v;
		}
	}
}
