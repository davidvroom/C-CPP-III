#ifndef INCLUDED_INTTYPE_H_
#define INCLUDED_INTTYPE_H_

template <int x>
struct IntType
{
	enum { value = x };
};

#endif