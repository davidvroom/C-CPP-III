#ifndef INCLUDED_TRAIT_H_
#define INCLUDED_TRAIT_H_

#include <vector>

// generic case for when LHS is Expr
template <typename Expr>
struct Trait
{
	typedef typename Expr::VecType VecType;
	enum { isVector = 0 };
};

// specialization for when LHS is a vector
template<typename InType>
struct Trait<std::vector<InType>>
{
	typedef std::vector<InType> VecType;
	enum { isVector = 1 };
};

#endif