#ifndef INCLUDED_TYPE_H_
#define INCLUDED_TYPE_H_

#include "typeidx.h"

template <typename Needle, typename ...Haystack>
struct Type
{	
	enum 
	{ 
		//located = sizeof ...(Params) - TypeIdx<Needle, Params...>::remaining
		located = TypeIdx<1, Needle, Haystack...>::position
	};	
};

template <typename Needle>
struct Type<Needle>
{
	enum { located = 0 };
};

#endif