#ifndef INCLUDED_INTVALUE_
#define INCLUDED_INTVALUE_

#include "../base/base.h"
#include <iostream>

class IntValue: public Base<IntValue>
{
	friend Base<IntValue>;

	int d_intValue = 100;
	std::ostream &insertInto(std::ostream &out) const;
};

std::ostream &IntValue::insertInto(std::ostream &out) const
{
	return out << d_intValue;
}

#endif
