#include "semaphore.h"
#include <iostream>

bool fun(int num)
{
	return true;
}

int main()
{
	Semaphore consumer;
	consumer.wait(fun, 2);
}