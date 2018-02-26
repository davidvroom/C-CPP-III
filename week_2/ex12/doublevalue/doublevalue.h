#ifndef INCLUDED_DOUBLEVALUE_
#define INCLUDED_DOUBLEVALUE_

#include "../base/base.h"
#include <iostream>

class DoubleValue: public Base<DoubleValue>
{
	double d_doubleValue = 10.81;

	private:
		std::ostream &insertInto(std::ostream &out);
};

std::ostream &DoubleValue::insertInto(std::ostream &out)
{
	return out << d_doubleValue;
}

#endif
