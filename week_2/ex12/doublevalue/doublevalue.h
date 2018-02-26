#ifndef INCLUDED_DOUBLEVALUE_
#define INCLUDED_DOUBLEVALUE_

#include "../base/base.h"
#include <iostream>

class DoubleValue: public Base<DoubleValue>
{
	friend Base<DoubleValue>;

	double d_doubleValue = 10.81;
	std::ostream &insertInto(std::ostream &out) const;
};

std::ostream &DoubleValue::insertInto(std::ostream &out) const
{
	return out << d_doubleValue;
}

#endif
