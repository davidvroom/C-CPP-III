#ifndef INCLUDED_TYPE_H_
#define INCLUDED_TYPE_H_

#include <cstddef>	// size_t

template <typename Needle, typename ...Haystack>
class Type
{	
	template <size_t idx, typename InnerNeedle, typename Next, typename ...Rest>
	struct TypeIdx
	{
		enum { position = TypeIdx<idx + 1, Needle, Rest...>::position };
	};

	public:
		enum 
		{ 
			located = TypeIdx<1, Needle, Haystack...>::position
		};	
};

// specialization for needle found somewhere in the middle of haystack
template <typename Needle, typename ...Haystack>
template <size_t idx, typename ...Rest>
struct Type<Needle, Haystack...>::TypeIdx<idx, Needle, Needle, Rest...>
{
	enum { position = idx };
};

// specialization for needle found at end of haystack
template <typename Needle, typename ...Haystack>
template <size_t idx>
struct Type<Needle, Haystack...>::TypeIdx<idx, Needle, Needle>
{
	enum { position = idx };
};

// specialization for needle not found, i.e. the end condition
template <typename Needle, typename ...Haystack>
template <size_t idx, typename Next>
struct Type<Needle, Haystack...>::TypeIdx<idx, Needle, Next>
{
	enum { position = 0 };
};

// specialization for only one tt argument
template <typename Needle>
struct Type<Needle>
{
	enum { located = 0 };
};

#endif