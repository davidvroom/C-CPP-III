#include <iostream>
#include "pointerunion.h"

template <typename Type>
Type add(Type const &lhs, Type const &rhs);

void fun()
{
	PointerUnion pu = { add };

	std::cout << pu.vp << '\n';
}
