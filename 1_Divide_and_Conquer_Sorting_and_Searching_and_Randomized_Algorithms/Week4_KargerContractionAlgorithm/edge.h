#ifndef EDGE_H
#define EDGE_H

class edge
{
public:
	edge(const edge& other);		//copy constructor
	edge(edge&& other) noexcept;	//move constructor
	edge& operator=(const edge& other);		//copy assignment
	edge& operator=(edge&& other) noexcept;	//move assignment

	edge() :s_(0), d_(0) {}
	edge(const size_t src, const size_t dest) :s_(src), d_(dest) {}
	size_t src() const { return s_; }
	size_t dest() const { return d_; }
private:

	size_t s_;
	size_t d_;
};

#endif