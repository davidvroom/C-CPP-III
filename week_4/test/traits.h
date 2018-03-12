#ifndef INCLUDED_TRAITS_H_
#define INCLUDED_TRAITS_H_

//#include "ifelse.h"

template <typename Type>
struct Traits
{
	struct Char2
	{
		char data[2];
	};



	template <typename T>
	struct NoFloat
	{
		enum{ value = T{} };
	};

	enum value{ };

	template <int T>
	struct VtoT
	{};

	template <typename IntType>			// static?
	static Char2 fun(VtoT<0> arg);

	template <typename NonIntType>		// static?
	static char fun(VtoT<0.0>);

	enum { isIntType = sizeof(fun(VtoT<Type{0}>)) == sizeof(Char2) };

	
	//static const bool cond = Type{0.1} == 0;
	//enum { isIntType = ( (Type{} + 0.1) == 0) };

	//typedef typename IfElse<isClass, Type const &, Type>::type ReturnType;
};
/*
template <Type>
struct Convert
{
	enum{ value = ... } float
}
*/


#endif

