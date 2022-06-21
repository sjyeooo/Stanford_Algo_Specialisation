#include "ngraph.hpp"
#include <list>
#include <memory>
#include <stack>
#include <vector>

class strongly_connected_components
{
  public:
	strongly_connected_components();
	strongly_connected_components(std::shared_ptr<NGraph::tGraph<size_t>> graph,
								  std::shared_ptr<NGraph::tGraph<size_t>> graph_reverse);

	~strongly_connected_components();

	void run();

	std::vector<size_t> get_scc_sizes()
	{
		return scc_sizes_;
	}

  private:
	std::shared_ptr<NGraph::tGraph<size_t>> graph_;
	std::shared_ptr<NGraph::tGraph<size_t>> graph_reverse_;

	void DFS1(size_t v);

	void DFS2(size_t v);

	std::unique_ptr<std::stack<size_t>> topological_order_;
	std::unique_ptr<std::vector<unsigned char>> visited_dfs1_;
	std::unique_ptr<std::vector<unsigned char>> visited_dfs2_;
	std::unique_ptr<std::list<size_t>> dfs_visit_order_;
	std::vector<size_t> scc_sizes_;
};