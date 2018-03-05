#ifndef INCLUDED_DISPLAY_H_
#define INCLUDED_DISPLAY_H_

#include <ostream>
#include <cstddef>

template<char First, char ...Rest>
struct Chars
{
	enum { value = First };
};


//template <bool selector, size_t DECIMAL, size_t BASE, char ...Rest>
template <size_t DECIMAL, size_t BASE, char ...Acc>
struct Display
{
	using Type = typename Display<DECIMAL/BASE, BASE, DECIMAL % BASE, Acc...>::Type;
};

template <size_t BASE, char ...Acc>
struct Display<0, BASE, Acc...>
{
	using Type = Chars<Acc...>;
};



/*

template <size_t DECIMAL, size_t BASE, char ...Rest>
struct Display<true, DECIMAL, BASE, Rest...>
{
	using Type = Chars<Rest...>;
};

*/

#endif