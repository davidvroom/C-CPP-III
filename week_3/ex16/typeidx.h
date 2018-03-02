#ifndef INCLUDED_TYPEIDX_H_
#define INCLUDED_TYPEIDX_H_


#include <cstddef>	// size_t

// generic 
template <size_t idx, typename Needle, typename Next, typename ...Params>
struct TypeIdx
{
	enum { position = TypeIdx<idx + 1, Needle, Params...>::position };
};

// specialization for needle found somewhere in the middle of haystack
template <size_t idx, typename Needle, typename ...Params>
struct TypeIdx<idx, Needle, Needle, Params...>
{
	enum { position = idx };
};

// specialization for needle found at end of haystack
template <size_t idx, typename Needle>
struct TypeIdx<idx, Needle, Needle>
{
	enum { position = idx };
};

// specialization for needle not found, i.e. the end condition
template <size_t idx, typename Needle, typename Next>
struct TypeIdx<idx, Needle, Next>
{
	enum { position = 0 };
};

#endif