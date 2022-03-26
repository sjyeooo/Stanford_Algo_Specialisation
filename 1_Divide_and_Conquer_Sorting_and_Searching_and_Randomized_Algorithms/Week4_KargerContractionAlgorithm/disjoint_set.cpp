#include "disjoint_set.h"

disjoint_set::disjoint_set(const size_t n)
{
	set_.resize(n);
	for (size_t i = 0u; i < n; i++)
	{
		set_[i].parent = i;
		set_[i].rank = 0;
	}
}

disjoint_set::disjoint_set(const std::vector<size_t>& list)
{
	set_.resize(list.size());
	for (size_t i = 0u; i < list.size(); i++)
	{
		set_[i].parent = list[i];
		set_[i].rank = 0;
	}
}

size_t disjoint_set::find(const size_t a)
{
	//Recursively go through the set to look for the parent. (Normal find routine)
	//while setting the parent of the current node to the higher level (for path compression)
	if (set_[a].parent != a)
	{
		//Set the parent of current node for path compression
		set_[a].parent = find(set_[a].parent);
	}

	return set_[a].parent;
}

bool disjoint_set::is_connected(const size_t a, const size_t b)
{
	return find(a) == find(b);
}

void disjoint_set::Union(const size_t a, const size_t b)
{
	const size_t a_root = find(a);
	const size_t b_root = find(b);

	//Same root
	if (a_root == b_root)
		return;

	//A Tree ranked higher
	if(set_[a_root].rank > set_[b_root].rank)
	{
		set_[b_root].parent = a;
	}
	//B Tree is bigger or same rank
	else if (set_[b_root].rank > set_[a_root].rank)
	{
		set_[a_root].parent = b;
	}
	else
	{
		set_[a_root].parent = b;
		set_[b_root].rank++;
	}
}