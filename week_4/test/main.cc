#include <cstddef>

#include "traits.h"
#include <iostream>

int main()
{
	/*
	int const iv = 5;
	unsigned long const sv = 4;
	float const fv = 2.5;


	enum out{ in };
	auto var = out::in + iv;
	//fun(iv);
	

	int iv{};
	auto iets = int{} + 0.1;
	bool cond = iv == 0;
	std::cout << iets << '\n';
	*/
	std::cout << Traits<int>::isIntType << '\n';

}