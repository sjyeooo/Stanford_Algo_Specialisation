#include <memory>
#include <queue>
#include <vector>

#include "ngraph.hpp"

class depth_first_search
{
  public:
	depth_first_search();
	depth_first_search(std::shared_ptr<NGraph::Graph> g, int src);
	~depth_first_search();

	void print_search_path(std::string filename);
	std::queue<unsigned int> get_search_path();

	bool has_path_to(unsigned int v)
	{
		return marked_[v];
	}

  private:
	void dfs(unsigned int v);

	std::queue<unsigned int> search_path_;
	std::shared_ptr<NGraph::Graph> g_;
	std::vector<bool> marked_;
	std::vector<unsigned int> edge_to_;
};