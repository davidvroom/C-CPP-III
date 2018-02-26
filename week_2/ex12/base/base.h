#ifndef INCLUDED_BASE_
#define INCLUDED_BASE_

#include <iostream>

template <class Derived>
class Base;

template <class Derived>
std::ostream &operator<<(std::ostream &out, Base<Derived> const &base);		

template <class Derived>
class Base
{
	friend std::ostream &operator<<<Derived>(std::ostream &out, Base<Derived> const &base);		
	std::ostream &insertInto(std::ostream &out) const;
};

template <class Derived>
inline std::ostream &operator<<(std::ostream &out, Base<Derived> const &base)
{
    return base.insertInto(out);
}

template <class Derived>
inline std::ostream &Base<Derived>::insertInto(std::ostream &out) const
{
	return static_cast<Derived const*>(this)->insertInto(out);
}

#endif
