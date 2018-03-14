#ifndef INCLUDED_INSERTABLE_H_	
#define INCLUDED_INSERTABLE_H_

#include <ostream>

template <template <typename> class Container, typename Type>
struct Insertable: public Container<Type>
{
	Insertable() = default;
	explicit Insertable(Container<Type> const &initCont);
	explicit Insertable(Container<Type> &&initCont);
	explicit Insertable(Type const &initDataEl);
	explicit Insertable(Type &&initDataEl);
};

template<template <typename> class Container, typename Type>
std::ostream &operator<<(
	std::ostream &out, Insertable<Container, Type> const &obj)
{
	for (size_t idx = 0, end = obj.size(); idx != end; ++idx)
		out << obj[idx] << '\n';
	return out;
}

#endif