#include <memory>
#include <queue>
#include <vector>

#include "ngraph.hpp"

class breath_first_search
{
  public:
	breath_first_search();
	breath_first_search(std::shared_ptr<NGraph::Graph> g, int src);
	~breath_first_search();

	void print_search_path(std::string filename);

	bool has_path_to(unsigned int v)
	{
		return marked_[v];
	}

  private:
	void bfs(unsigned int s);

	std::queue<unsigned int> search_path_;
	std::shared_ptr<NGraph::Graph> g_;
	std::vector<bool> marked_;
	std::vector<unsigned int> edge_to_;
	std::vector<unsigned int> dist_to_;
};