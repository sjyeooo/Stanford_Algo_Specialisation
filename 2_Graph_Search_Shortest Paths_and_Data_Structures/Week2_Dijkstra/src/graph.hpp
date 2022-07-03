#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cassert>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

template <class V, class E> class graph
{
  private:
	class vertex;
	class edge;

  public:
	friend void swap(graph &lhs, graph &rhs)
	{
		std::swap(lhs.m_vertices, rhs.m_vertices);
		std::swap(lhs.m_freed_vertex_ids, rhs.m_freed_vertex_ids);

		std::swap(lhs.m_edges, rhs.m_edges);
		std::swap(lhs.m_freed_edge_ids, rhs.m_freed_edge_ids);
	}

	// Functions ///////////////////////////////////////////////////////////////

	auto add_vertex(const V &data) -> std::ptrdiff_t
	{
		std::ptrdiff_t new_vertex_id = 0;

		if (!m_freed_vertex_ids.empty())
		{
			new_vertex_id = *m_freed_vertex_ids.begin();
			m_freed_vertex_ids.erase(new_vertex_id);
			m_vertices[new_vertex_id] = vertex{new_vertex_id, data};
		}
		else
		{
			new_vertex_id = std::size(m_vertices);
			m_vertices.emplace_back(new_vertex_id, data);
		}

		return new_vertex_id;
	}

	auto vertex_data(std::ptrdiff_t vertex_id) const -> const V &
	{
		assert(is_vertex_present(vertex_id));

		return m_vertices[vertex_id].data();
	}

	auto is_vertex_present(std::ptrdiff_t vertex_id) const -> bool
	{
		return is_id_in_use(vertex_id, (std::size(m_vertices) - 1), m_freed_vertex_ids);
	}

	void remove_vertex(std::ptrdiff_t vertex_id)
	{
		m_freed_vertex_ids.insert(vertex_id);

		for (const auto &edge : m_edges)
		{
			if ((edge.source_vertex_id() == vertex_id) || (edge.target_vertex_id() == vertex_id))
			{
				m_vertices[edge.source_vertex_id()].remove_edge(edge.id());
				m_freed_edge_ids.insert(edge.id());
			}
		}
	}

	auto amount_vertices() const -> std::ptrdiff_t
	{
		return (std::size(m_vertices) - std::size(m_freed_vertex_ids));
	}

	void clear()
	{
		*this = graph<V, E>{};
	}

	auto add_edge(std::ptrdiff_t from_vertex_id, std::ptrdiff_t to_vertex_id, const E &data) -> std::ptrdiff_t
	{
		assert(is_vertex_present(from_vertex_id));
		assert(is_vertex_present(to_vertex_id));

		std::ptrdiff_t new_edge_id = 0;

		if (!m_freed_edge_ids.empty())
		{
			new_edge_id = *m_freed_edge_ids.begin();
			m_freed_edge_ids.erase(new_edge_id);
			m_edges[new_edge_id] = edge{new_edge_id, from_vertex_id, to_vertex_id, data};
		}
		else
		{
			new_edge_id = std::size(m_edges);
			m_edges.emplace_back(new_edge_id, from_vertex_id, to_vertex_id, data);
		}

		m_vertices[from_vertex_id].add_edge(new_edge_id);

		return new_edge_id;
	}

	auto add_undirected_edge(std::ptrdiff_t from_vertex_id, std::ptrdiff_t to_vertex_id, const E &data)
		-> std::pair<std::ptrdiff_t, std::ptrdiff_t>
	{
		std::ptrdiff_t a = add_edge(from_vertex_id, to_vertex_id, data);
		std::ptrdiff_t b = add_edge(to_vertex_id, from_vertex_id, data);

		return {a, b};
	}

	auto edge_data(std::ptrdiff_t edge_id) const -> const E &
	{
		assert(is_edge_present(edge_id));

		return m_edges[edge_id].data();
	}

	auto edge_source_vertex_id(std::ptrdiff_t edge_id) const -> std::ptrdiff_t
	{
		return m_edges[edge_id].source_vertex_id();
	}

	auto edge_target_vertex_id(std::ptrdiff_t edge_id) const -> std::ptrdiff_t
	{
		return m_edges[edge_id].target_vertex_id();
	}

	auto is_edge_present(std::ptrdiff_t edge_id) const -> bool
	{
		return is_id_in_use(edge_id, (std::size(m_edges) - 1), m_freed_edge_ids);
	}

	void remove_edge(std::ptrdiff_t edge_id)
	{
		m_freed_edge_ids.insert(edge_id);
	}

	auto amount_edges() const -> std::ptrdiff_t
	{
		return (std::size(m_edges) - std::size(m_freed_edge_ids));
	}

	void clear_edges()
	{
		m_edges.clear();
		m_freed_edge_ids.clear();

		for (auto &v : m_vertices)
		{
			v.clear_edges();
		}
	}

	auto empty() const -> bool
	{
		return (amount_vertices() == 0);
	}

	auto edge_ids(std::ptrdiff_t vertex_id) const -> std::set<std::ptrdiff_t>
	{
		assert(is_vertex_present(vertex_id));

		return m_vertices[vertex_id].edge_ids();
	}

	auto vertex_ids() const -> std::set<std::ptrdiff_t>
	{
		std::set<std::ptrdiff_t> ids;

		for (std::ptrdiff_t i = 0; i < std::size(m_vertices); i++)
		{
			if (!(m_freed_vertex_ids.count(i) > 0))
			{
				ids.insert(i);
			}
		}

		return ids;
	}

	auto edge_ids() const -> std::set<std::ptrdiff_t>
	{
		std::set<std::ptrdiff_t> ids;

		for (std::ptrdiff_t i = 0; i < std::size(m_edges); i++)
		{
			if (!(m_freed_vertex_ids.count(i) > 0))
			{
				ids.insert(i);
			}
		}

		return ids;
	}

	void transpose()
	{
		for (auto &edge : m_edges)
		{
			m_vertices[edge.source_vertex_id()].remove_edge(edge.id());
			edge.transpose();
			m_vertices[edge.source_vertex_id()].add_edge(edge.id());
		}
	}

	// Operators ///////////////////////////////////////////////////////////////

	friend auto operator<<(std::ostream &os, const graph &object) -> std::ostream &
	{
		os << object.to_json().dump(4);

		return os;
	}

	// Nested classes //////////////////////////////////////////////////////////

  private:
	class edge
	{
	  public:
		edge(std::ptrdiff_t id, std::ptrdiff_t source_vertex_id, std::ptrdiff_t target_vertex_id, const E &data) :
			m_id{id},
			m_source_vertex_id{source_vertex_id},
			m_target_vertex_id{target_vertex_id},
			m_data{data}
		{
		}

		auto id() const -> std::ptrdiff_t
		{
			return m_id;
		}

		auto source_vertex_id() const -> std::ptrdiff_t
		{
			return m_source_vertex_id;
		}

		auto target_vertex_id() const -> std::ptrdiff_t
		{
			return m_target_vertex_id;
		}

		auto data() const -> const E &
		{
			return m_data;
		}

		void transpose()
		{
			std::swap(m_source_vertex_id, m_target_vertex_id);
		}

	  private:
		std::ptrdiff_t m_id;
		std::ptrdiff_t m_source_vertex_id;
		std::ptrdiff_t m_target_vertex_id;
		E m_data;
	};

	class vertex
	{
	  public:
		vertex(std::ptrdiff_t id, const V &data) : m_id{id}, m_data{data}
		{
		}

		auto id() const -> std::ptrdiff_t
		{
			return m_id;
		}

		void add_edge(std::ptrdiff_t edge_id)
		{
			m_edge_ids.insert(edge_id);
		}

		void remove_edge(std::ptrdiff_t edge_id)
		{
			m_edge_ids.erase(edge_id);
		}

		void clear_edges()
		{
			m_edge_ids.clear();
		}

		auto edge_ids() const -> std::set<std::ptrdiff_t>
		{
			return m_edge_ids;
		}

		auto data() const -> const V &
		{
			return m_data;
		}

	  private:
		std::ptrdiff_t m_id;
		std::set<std::ptrdiff_t> m_edge_ids;
		V m_data;
	};

	auto is_id_in_use(std::ptrdiff_t id, std::ptrdiff_t max_id_in_use, const std::set<std::ptrdiff_t> &freed_ids) const
		-> bool
	{
		return ((id >= 0) && (id <= max_id_in_use) && !(freed_ids.count(id) > 0));
	}

	std::vector<vertex> m_vertices;
	std::set<std::ptrdiff_t> m_freed_vertex_ids;

	std::vector<edge> m_edges;
	std::set<std::ptrdiff_t> m_freed_edge_ids;
};

#endif
