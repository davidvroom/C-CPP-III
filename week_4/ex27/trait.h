#ifndef INCLUDED_TRAIT_H_
#define INCLUDED_TRAIT_H_

#include <vector>

// generic case
template <typename Expr>
struct Trait
{
	typedef typename Expr::VecType VecType;
};

// specialization
template<typename InType>
struct Trait<std::vector<InType>>
{
	typedef std::vector<InType> VecType;
};

#endif