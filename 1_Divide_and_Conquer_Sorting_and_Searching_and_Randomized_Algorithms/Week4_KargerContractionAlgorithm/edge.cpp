#include "edge.h"

edge::edge(const edge& other)
	: s_(other.s_),
	d_(other.d_)
{
}

edge::edge(edge&& other) noexcept
	: s_(other.s_),
	d_(other.d_)
{
}

edge& edge::operator=(const edge& other)
{
	if (this == &other)
		return *this;
	s_ = other.s_;
	d_ = other.d_;
	return *this;
}

edge& edge::operator=(edge&& other) noexcept
{
	if (this == &other)
		return *this;
	s_ = other.s_;
	d_ = other.d_;
	return *this;
}