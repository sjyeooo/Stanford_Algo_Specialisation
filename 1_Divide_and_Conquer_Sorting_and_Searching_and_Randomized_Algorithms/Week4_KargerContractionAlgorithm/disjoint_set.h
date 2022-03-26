#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>

class disjoint_set
{
	typedef struct
	{
		size_t parent;
		size_t rank;
	} disjoint_set_typ;

public:
	disjoint_set(size_t n);
	disjoint_set(const std::vector<size_t>& list);

	size_t find(size_t a);
	bool is_connected(size_t a, size_t b);
	void Union(size_t a, size_t b);

private:
	std::vector<disjoint_set_typ> set_;
};

#endif