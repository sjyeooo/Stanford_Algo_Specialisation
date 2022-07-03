#include "dijkstra.h"

dijkstra::dijkstra() = default;

dijkstra::dijkstra(const std::shared_ptr<graph<std::ptrdiff_t, std::size_t>> &Graph, std::ptrdiff_t src) :
	m_graph(Graph),
	m_src(src)
{
	// Initialise parent and distances
	for (const auto vertex : m_graph->vertex_ids())
	{
		m_vertex_parent_id[vertex] = no_parent;
		m_vertex_distance[vertex] = infinity;
	}
	m_vertex_distance[m_src] = 0;

	// Lambda function to compare between two distances
	auto comparator = [this](std::ptrdiff_t lhs, std::ptrdiff_t rhs) {
		return (m_vertex_distance.at(lhs) > m_vertex_distance.at(rhs));
	};

	std::priority_queue<std::ptrdiff_t, std::vector<std::ptrdiff_t>, decltype(comparator)> vertex_ids_to_process(
		comparator);
	vertex_ids_to_process.push(m_src);

	std::unordered_set<std::ptrdiff_t> determined_vertex_ids;

	while (!vertex_ids_to_process.empty())
	{
		std::ptrdiff_t vertex_id = vertex_ids_to_process.top();
		vertex_ids_to_process.pop();

		if (!(determined_vertex_ids.count(vertex_id) > 0))
		{
			determined_vertex_ids.insert(vertex_id);

			for (const auto &edge_id : m_graph->edge_ids(vertex_id))
			{
				std::ptrdiff_t neighbor_vertex_id = m_graph->edge_target_vertex_id(edge_id);

				std::ptrdiff_t new_distance = (m_vertex_distance[vertex_id] + m_graph->edge_data(edge_id));
				if (new_distance < m_vertex_distance[neighbor_vertex_id])
				{
					m_vertex_distance[neighbor_vertex_id] = new_distance;
					m_vertex_parent_id[neighbor_vertex_id] = vertex_id;
					vertex_ids_to_process.push(neighbor_vertex_id);
				}
			}
		}
	}
}

auto dijkstra::search_path(std::ptrdiff_t target_vertex_id) const -> std::vector<std::ptrdiff_t>
{
	return construct_path(target_vertex_id);
}

auto dijkstra::dist_to(std::ptrdiff_t target_vertex_id) const -> std::ptrdiff_t
{
	return m_vertex_distance.at(target_vertex_id);
}

auto dijkstra::construct_path(std::ptrdiff_t target_vertex_id) const -> std::vector<std::ptrdiff_t>
{
	std::vector<std::ptrdiff_t> path_vertex_ids;

	std::ptrdiff_t vertex_id = target_vertex_id;
	while (vertex_id != m_src)
	{
		path_vertex_ids.push_back(vertex_id);
		vertex_id = m_vertex_parent_id.at(vertex_id);
	}

	path_vertex_ids.push_back(m_src);

	std::reverse(path_vertex_ids.begin(), path_vertex_ids.end());

	return path_vertex_ids;
}
