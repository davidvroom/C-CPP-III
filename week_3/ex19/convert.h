#ifndef INCLUDED_CONVERT_H_
#define INCLUDED_CONVERT_H_

#include <ostream>
#include <cstddef>

template <size_t DECIMAL, size_t BASE>
struct Convert
{
	struct CP
	{};
};

template <size_t DECIMAL, size_t BASE>
std::ostream &operator<<(std::ostream &out, typename Convert<DECIMAL, BASE>::CP const &obj) 
{
	return out << "insertion operator"; 
}

#endif