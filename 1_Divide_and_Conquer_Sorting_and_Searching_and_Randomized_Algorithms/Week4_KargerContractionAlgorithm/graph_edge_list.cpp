#include "graph_edge_list.h"

#include <iostream>

graph_edge_list::graph_edge_list() :
	num_vertices_(0)
{
}

graph_edge_list::graph_edge_list(const size_t v) :
	num_vertices_(v)
{
}

void graph_edge_list::add_edge(const size_t src, const size_t dest)
{
	//Increase number of vertices if source and destination is higher than total number of vertices
	num_vertices_ = std::max(src + 1, num_vertices_);
	num_vertices_ = std::max(dest + 1, num_vertices_);

	add_edge_private(src, dest);
}

void graph_edge_list::add_edge_check_bounds(const size_t src, const size_t dest)
{
	if (src < num_vertices_ &&
		dest < num_vertices_)
	{
		add_edge_private(src, dest);
	}
}

edge graph_edge_list::get_edge(size_t i) const
{
	return edge_list_.at(i);
}

void graph_edge_list::print_graph_stats() const
{
	std::cout << "num_vertices = " << vertices() << " num_edges = " << edges() << std::endl;
}

void graph_edge_list::add_edge_private(size_t src, size_t dest)
{
	edge_list_.emplace_back(src, dest);
}
