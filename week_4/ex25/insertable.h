#ifndef INCLUDED_INSERTABLE_H_	
#define INCLUDED_INSERTABLE_H_

#include <ostream>
#include <iostream>
#include <utility>

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

template <template <typename> class Container, typename Type>
Insertable<Container, Type>::Insertable(Container<Type> const &initCont)
:
	Container<Type>(initCont)
{}

template <template <typename> class Container, typename Type>
Insertable<Container, Type>::Insertable(Container<Type> &&initCont)
:
	Container<Type>( std::move(initCont) )
{ std::cout << "move construction1\n"; }

template <template <typename> class Container, typename Type>
Insertable<Container, Type>::Insertable(Type const &initDataEl)
:
	Container<Type>(1, initDataEl) 
{}

template <template <typename> class Container, typename Type>
Insertable<Container, Type>::Insertable(Type &&initDataEl)
:
	Container<Type>(1, std::move(initDataEl)) 
{ std::cout << "move construction2\n"; }

#endif