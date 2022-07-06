#include "median_heap.h"

void median_heap::push(int input)
{
	// Initialisation step
	if (smaller.empty())
	{
		smaller.push(input);
		return;
	}

	// Add element to respective heap
	if (input <= smaller.top()) // Input should belong to smaller group
	{
		smaller.push(input);
	}
	else
	{
		larger.push(input);
	}
	rebalance_pq();
}

auto median_heap::median() const -> int
{
	if (smaller.size() >= larger.size())
	{
		return (smaller.top());
	}
	else // (smaller.size() < larger.size())
	{
		return (larger.top());
	}
}

void median_heap::rebalance_pq()
{
	if (smaller.size() > (larger.size() + 1)) // Smaller heap is too large
	{
		larger.push(smaller.top());
		smaller.pop();
	}
	else if (larger.size() > (smaller.size() + 1))
	{
		smaller.push(larger.top());
		larger.pop();
	}
}