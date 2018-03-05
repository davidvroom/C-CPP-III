#ifndef INCLUDED_CONVERT_H_
#define INCLUDED_CONVERT_H_

#include <ostream>
#include <cstddef> 
#include "display.h"

template <size_t DECIMAL, size_t BASE>
struct Convert
{
	using CP = typename Display<(DECIMAL % BASE) / 10, DECIMAL, BASE>::Type;
};

// Specialization for the (rare) case that zero is given as input to Decimal
template <size_t BASE>
struct Convert<0, BASE>
{	
	using CP = Chars<'0'>;
};

template <char First, char ...Rest>
std::ostream &operator<<(std::ostream &out, Chars<First, Rest...> const &obj)
{
	return out << char{ Chars<First, Rest...>::value }
			   << Chars<Rest...>{};
}

template <char Last>
std::ostream &operator<<(std::ostream &out, Chars<Last> const &obj)
{
	return out << char{ Chars<Last>::value };
}

#endif
