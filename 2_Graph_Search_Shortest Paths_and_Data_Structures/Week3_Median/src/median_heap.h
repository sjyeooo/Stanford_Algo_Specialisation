#ifndef MEDIAN_HEAP_H
#define MEDIAN_HEAP_H

#include <memory>
#include <queue>

class median_heap
{
  public:
	median_heap() = default;
	~median_heap() = default;

	// Add elements
	void push(int input);

	// Get current median
	auto median() const -> int;

  private:
	void rebalance_pq();

	// Provides the maximum of the smallest half elements.
	std::priority_queue<int> smaller;								   // Contains smaller half of the elements
	std::priority_queue<int, std::vector<int>, std::greater<>> larger; // Contains larger half of the elements
};

#endif