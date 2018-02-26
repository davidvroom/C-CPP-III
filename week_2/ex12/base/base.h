#ifndef INCLUDED_BASE_
#define INCLUDED_BASE_

#include <iostream>

template <class Derived>
class Base
{
	friend std::ostream &operator<<(std::ostream &out, Base<Derived> const &base);		
};

template <class Derived>
inline std::ostream &operator<<(std::ostream &out, Base<Derived> const &base)
{
    return base.insertInto(out);
}

#endif
