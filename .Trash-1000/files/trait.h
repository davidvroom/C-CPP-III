/*#ifndef INCLUDED_TRAIT_H_
#define INCLUDED_TRAIT_H_


// generic case for when LHS is Expr
template <typename Expr>
struct Trait
{
	typedef typename Expr::VecType VecType;
};

// specialization for when LHS is a vector
template<typename InType>
struct Trait<std::vector<InType>>
{
	typedef std::vector<InType> VecType;
};

#endif*/