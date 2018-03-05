#ifndef INCLUDED_DISPLAY_H_
#define INCLUDED_DISPLAY_H_

#include <ostream>
#include <cstddef>

struct OneChar
{
	enum { value = 'a' + 'b'};
};

template <bool selector, size_t DECIMAL, size_t BASE>
struct Display
{
	using Type = typename Display<true, DECIMAL, BASE>::Type;
};

template <size_t DECIMAL, size_t BASE>
struct Display<true, DECIMAL, BASE>
{
	using Type = OneChar;
};



#endif
