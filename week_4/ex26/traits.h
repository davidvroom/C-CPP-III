#ifndef INCLUDED_TRAITS_H_
#define INCLUDED_TRAITS_H_

#include "ifelse.h"

template <typename Type>
struct Traits
{
	struct Char2
	{
		char data[2];
	};

	template <typename ClassType>			// static?
	static Char2 fun(void (ClassType::*)());

	template <typename NonClassType>		// static?
	static char fun(...);

	enum { isClass = sizeof(fun<Type>(0)) == sizeof(Char2) };

	typedef typename IfElse<isClass, Type const &, Type>::type ReturnType;
};
/*
template <Type>
struct Convert
{
	enum{ value = ... } float
}
*/


#endif

