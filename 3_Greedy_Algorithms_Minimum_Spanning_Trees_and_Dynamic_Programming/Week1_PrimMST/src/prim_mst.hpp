#ifndef PRIM_HPP
#define PRIM_HPP

#include "graph.hpp"

#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

template <class V, class E> class prim_mst
{
	using edge_typ = std::pair<E, std::ptrdiff_t>;

  public:
	prim_mst(const graph<V, E> &graph_)
	{
		auto vertex_ids = graph_.vertex_ids();
		std::ptrdiff_t start_vertex_id = *std::min_element(vertex_ids.begin(), vertex_ids.end());

		// Create mst of same number of vertices as input graph
		mst_ = graph_;
		mst_.clear_edges();

		std::priority_queue<edge_typ, std::vector<edge_typ>, std::greater<edge_typ>> pq;

		for (const auto &id : graph_.edge_ids(start_vertex_id))
		{
			pq.push({graph_.edge_data(id), id});
		}

		// Remember the vertices that have been processed
		std::set<std::ptrdiff_t> vertices_in_tree;
		vertices_in_tree.insert(start_vertex_id);

		while (!pq.empty())
		{
			const edge_typ edge_data = pq.top();
			const E weight = edge_data.first;
			const std::ptrdiff_t id = edge_data.second;
			pq.pop();
			const std::ptrdiff_t target_vertex_id = graph_.edge_target_vertex_id(id);

			// vertex is not in the group which we have processed
			if (vertices_in_tree.count(target_vertex_id) == 0)
			{
				const auto source_vertex_id = graph_.edge_source_vertex_id(id);

				mst_.add_edge(source_vertex_id, target_vertex_id, weight);
				vertices_in_tree.insert(target_vertex_id);

				for (const auto &id : graph_.edge_ids(target_vertex_id))
				{
					pq.push({graph_.edge_data(id), id});
				}
			}
		}

		// Sum up edge weights
		for (const auto &id : mst_.edge_ids())
		{
			mst_costs_ += mst_.edge_data(id);
		}
	}

	graph<V, E> minimum_spanning_tree() const
	{
		return mst_;
	}

	inline int get_mst_weight() const
	{
		return mst_costs_;
	}

  private:
	graph<V, E> mst_;
	E mst_costs_ = 0;
};

#endif
