#include "breath_first_search.h"

#include <fstream>

breath_first_search::breath_first_search()
{
}

breath_first_search::breath_first_search(std::shared_ptr<NGraph::Graph> g, int src) :
	g_(g),
	marked_(g->num_vertices(), false),
	edge_to_(g->num_vertices(), 0),
	dist_to_(g->num_vertices(), UINT_MAX)
{
	bfs(src);
}

breath_first_search::~breath_first_search()
{
}

void breath_first_search::print_search_path(std::string filename)
{
	std::ofstream file_output(filename);
	std::queue<unsigned int> temp_queue = search_path_;

	while (!temp_queue.empty())
	{
		file_output << temp_queue.front() << std::endl;
		temp_queue.pop();
	}
}

void breath_first_search::bfs(unsigned int s)
{
	std::queue<unsigned int> q;
	q.push(s);
	dist_to_[s] = 0;
	marked_[s] = true;
	search_path_.push(s);
	q.push(s);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int w : g_->out_neighbors(v))
		{
			if (!marked_[w])
			{
				edge_to_[w] = v;
				dist_to_[w] = dist_to_[v] + 1;
				marked_[w] = true;
				search_path_.push(w);
				q.push(w);
			}
		}
	}
}