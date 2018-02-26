#ifndef INCLUDED_INTVALUE_
#define INCLUDED_INTVALUE_

#include "../base/base.h"
#include <iostream>

class IntValue: public Base<int>
{
	int d_intValue = 100;
	std::ostream &insertInto(std::ostream &out);
};

std::ostream &IntValue::insertInto(std::ostream &out)
{
	return out << d_intValue;
}

#endif
