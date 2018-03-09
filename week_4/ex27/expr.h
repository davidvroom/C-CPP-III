#ifndef INCLUDED_EXPR_H_
#define INCLUDED_EXPR_H_

template<typename LHS, typename RHS>
struct Expr
{
	LHS const &d_lhs;
	RHS const &d_rhs;

	Expr(LHS const &lhs, RHS const &rhs);
	value_type operator[](size_t idx) const;
	operator ObjType() const;
}

template<typename LHS, typename RHS>
operator