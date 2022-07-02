#include "strongly_connected_components.h"

strongly_connected_components::strongly_connected_components() = default;

strongly_connected_components::strongly_connected_components(const std::shared_ptr<NGraph::tGraph<size_t>> &graph,
															 std::shared_ptr<NGraph::tGraph<size_t>> graph_reverse) :
	graph_(graph),
	graph_reverse_(graph_reverse)
{
	visited_dfs1_ = std::make_unique<std::vector<unsigned char>>(graph->num_vertices(), 0);
	visited_dfs2_ = std::make_unique<std::vector<unsigned char>>(graph->num_vertices(), 0);
	topological_order_ = std::make_unique<std::stack<size_t>>();
	dfs_visit_order_ = std::make_unique<std::list<size_t>>();
}

strongly_connected_components::~strongly_connected_components() = default;

void strongly_connected_components::run()
{
	// Run DFS over all vertices in case there are vertex that cannot be reached from other vertex.
	for (size_t v = 0; v < graph_->num_vertices(); v++)
	{
		if (visited_dfs1_->at(v) == 0)
		{
			DFS1(v);
		}
	}

	// Iterate over all vertices in the order of decreasing f_values.
	while (!topological_order_->empty())
	{
		// Get the vertex with the (currently) highest f_value.
		size_t v = topological_order_->top();
		topological_order_->pop();

		// Start DFS for the vertex if it has not been visited during second dfs run
		if (visited_dfs2_->at(v) == 0)
		{
			dfs_visit_order_->clear();
			DFS2(v);
			// Add results from DFS search from source v
			scc_sizes_.push_back(dfs_visit_order_->size());
		}
	}
}

void strongly_connected_components::DFS1(size_t v)
{
	visited_dfs1_->at(v) = 1;

	// Iterate through all of v's outgoing edges
	for (const auto w : graph_->out_neighbors(v))
	{
		if (visited_dfs1_->at(w) == 0)
		{
			DFS1(w);
		}
	}

	// Stack of vertices sorted by completion time
	topological_order_->push(v);
}

void strongly_connected_components::DFS2(size_t v)
{
	visited_dfs2_->at(v) = 1;
	dfs_visit_order_->push_back(v);

	for (const size_t w : graph_reverse_->out_neighbors(v))
	{
		if (visited_dfs2_->at(w) == 0)
		{
			DFS2(w);
		}
	}
}