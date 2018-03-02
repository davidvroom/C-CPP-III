#ifndef INCLUDED_TYPE_H_
#define INCLUDED_TYPE_H_

#include "typeidx.h"

template <typename Needle, typename ...Params>
struct Type
{	
	enum 
	{ 
		located = sizeof ...(Params) - TypeIdx<Needle, Params...>::remaining
	};	
};

template <typename Needle>
struct Type<Needle>
{
	enum { located = 0 };
};

#endif