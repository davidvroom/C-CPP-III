#ifndef INCLUDED_DISPLAY_H_
#define INCLUDED_DISPLAY_H_

#include <ostream>
#include <cstddef>

template<char First, char ...Rest>
struct Chars
{
	enum { value = First };
};

// Generic template
template <bool IsNoDigit, size_t DECIMAL, size_t BASE, char ...Acc>
struct Display
{
	using Type = typename Display<((DECIMAL / BASE) % BASE) / 10, 
							      DECIMAL / BASE, 
							      BASE, 
							      DECIMAL % BASE + 87, 
							      Acc...
						  		  >::Type;
};

// Specialization for the character to add being a digit
template <size_t DECIMAL, size_t BASE, char ...Acc>
struct Display<false, DECIMAL, BASE, Acc...>
{
	using Type = typename Display<((DECIMAL / BASE) % BASE) / 10, 
								  DECIMAL / BASE, 
								  BASE, 
								  DECIMAL % BASE + 48, 
								  Acc...
								  >::Type;
};

// Specialization for ending recursion
template <size_t BASE, char ...Acc>
struct Display<false, 0, BASE, Acc...>
{
	using Type = Chars<Acc...>;
};

#endif