#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <limits>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "graph.hpp"

class dijkstra
{
  public:
	dijkstra();
	dijkstra(const std::shared_ptr<graph<std::ptrdiff_t, std::size_t>> &Graph, std::ptrdiff_t src);
	auto search_path(std::ptrdiff_t target_vertex_id) const -> std::vector<std::ptrdiff_t>;

	auto dist_to(std::ptrdiff_t target_vertex_id) const -> std::ptrdiff_t;

  private:
	auto construct_path(std::ptrdiff_t target_vertex_id) const -> std::vector<std::ptrdiff_t>;
	std::shared_ptr<graph<std::ptrdiff_t, std::size_t>> m_graph;

	std::ptrdiff_t m_src;
	std::unordered_map<std::ptrdiff_t, std::ptrdiff_t> m_vertex_parent_id;
	std::unordered_map<std::ptrdiff_t, std::ptrdiff_t> m_vertex_distance;

	constexpr static std::ptrdiff_t no_parent = -1;
	constexpr static std::ptrdiff_t infinity = std::numeric_limits<std::ptrdiff_t>::max();
};

#endif