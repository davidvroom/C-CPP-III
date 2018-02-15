#include <iostream>
#include "add.h"
#include "pointerunion.h"

void fun();

int main()
{
	PointerUnion pu = { add };
	std::cout << pu.vp << '\n';

	fun();
}
