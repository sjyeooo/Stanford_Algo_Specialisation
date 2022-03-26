#ifndef GRAPH_EDGE_LIST_H
#define GRAPH_EDGE_LIST_H

#include <vector>
#include "edge.h"

//Representation of graph using list of edges rather than adjacency list
class graph_edge_list
{

public:
	graph_edge_list();
	graph_edge_list(size_t v);

	void add_edge(size_t src, size_t dest);
	void add_edge_check_bounds(size_t src, size_t dest);

	size_t vertices() const { return num_vertices_; }
	size_t edges() const { return edge_list_.size(); }

	edge get_edge(size_t i) const;

	void print_graph_stats() const;
private:
	void add_edge_private(size_t src, size_t dest);
	std::vector<edge> edge_list_;
	size_t num_vertices_;
};

#endif