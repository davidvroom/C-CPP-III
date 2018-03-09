#ifndef INCLUDED_IFELSE_H_
#define INCLUDED_IFELSE_H_

template<bool selector, typename FirstType, typename SecondType>
struct IfElse
{
	typedef FirstType type;
};

template<typename FirstType, typename SecondType>
struct IfElse<false, FirstType, SecondType>
{
	typedef SecondType type;
};

#endif