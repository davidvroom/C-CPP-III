#include "storage.h"
#include <iostream>

int main()
{
	bool const var;
	std::cin >> var;
	Storage<int, var> storage;
	storage.add(3);
}