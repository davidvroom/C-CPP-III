#ifndef INCLUDED_CONVERT_H_
#define INCLUDED_CONVERT_H_

#include <ostream>
#include <cstddef>
#include "display.h"

template <size_t DECIMAL, size_t BASE>
struct Convert
{
	//using CP = typename ::Chars<'c', '8', '1'>;
	using CP = typename Display<false, DECIMAL, BASE>::Type;
};

#endif
