#ifndef INCLUDED_TYPEIDX_H_
#define INCLUDED_TYPEIDX_H_

template <typename Needle, typename Next, typename ...Params>
struct TypeIdx
{
	enum { remaining = TypeIdx<Needle, Params...>::remaining };
};

template <typename Needle, typename ...Params>
struct TypeIdx<Needle, Needle, Params...>
{
	enum { remaining = sizeof ...(Params) };
};

template <typename Needle>
struct TypeIdx<Needle, Needle>
{
	enum { remaining = 0 };
};


template <typename Needle, typename Next>
struct TypeIdx<Needle, Next>
{
	enum { remaining =  };
};

#endif