
#ifndef INCLUDED_DISPLAY_H_
#define INCLUDED_DISPLAY_H_

#include <ostream>
#include <cstddef>

template<char First, char ...Rest>
struct Chars
{
	enum { value = First };
};

template <bool selector, size_t DECIMAL, size_t BASE, char ...Rest>
struct Display
{
	using Type = typename Display<DECIMAL/BASE, DECIMAL, BASE, >::Type;
};

template <size_t DECIMAL, size_t BASE, char ...Rest>
struct Display<true, DECIMAL, BASE, Rest...>
{
	using Type = Chars<Rest...>;
};



#endif