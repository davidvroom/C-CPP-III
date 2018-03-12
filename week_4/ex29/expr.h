#ifndef INCLUDED_EXPR_H_
#define INCLUDED_EXPR_H_
#define HDR_ template <typename LHS, typename RHS, \
						template <typename> class Operation>
#define Expr_ Expr<LHS, RHS, Operation>

#include <functional>	// arithmetic function objects
#include <vector>

size_t nIndices = 0;
size_t nOperations = 0;

HDR_
class Expr
{
	template <typename ExprType>
	struct Trait;

	LHS const &d_lhs;
	RHS const &d_rhs;

	public:
		typedef typename Trait<LHS>::VecType VecType;
		typedef typename VecType::value_type value_type;		

		Expr(LHS const &lhs, RHS const &rhs);
		operator VecType() const;
		auto operator[](size_t idx) const;
		size_t size() const;
};

// generic case for when LHS is Expr
HDR_
template <typename ExprType>
struct Expr_::Trait
{
	typedef typename ExprType::VecType VecType;
	enum { isVector = 0 };
};

// specialization for when LHS is a vector
HDR_
template<typename InType>
struct Expr_::Trait<std::vector<InType>>
{
	typedef std::vector<InType> VecType;
	enum { isVector = 1 };
};

HDR_
Expr_::Expr(LHS const &lhs, RHS const &rhs)
:
	d_lhs(lhs),
	d_rhs(rhs)	
{}

HDR_
Expr_::operator VecType() const
{
	VecType ret;
	ret.reserve(size());

	for (size_t idx = 0, end = size(); idx != end; ++idx)
		ret.push_back(operator[](idx));

	return ret;
}

HDR_
auto Expr_::operator[](size_t idx) const
{
	(nIndices += Trait<LHS>::isVector) += Trait<RHS>::isVector; 

	++nOperations;
	return Operation<value_type>{}(d_lhs[idx], d_rhs[idx]);
}

HDR_
size_t Expr_::size() const
{
	return d_lhs.size();
}

// free binary operators
template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
	return Expr<LHS, RHS, std::plus>{ lhs, rhs };
}

template <typename LHS, typename RHS>
auto operator-(LHS const &lhs, RHS const &rhs)
{
	return Expr<LHS, RHS, std::minus>{ lhs, rhs };
}

template <typename LHS, typename RHS>
auto operator*(LHS const &lhs, RHS const &rhs)
{
	return Expr<LHS, RHS, std::multiplies>{ lhs, rhs };
}

template <typename LHS, typename RHS>
auto operator/(LHS const &lhs, RHS const &rhs)
{
	return Expr<LHS, RHS, std::divides>{ lhs, rhs };
}

#undef Expr_
#undef HDR_
#endif