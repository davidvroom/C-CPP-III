#ifndef INCLUDED_EXPR_H_
#define INCLUDED_EXPR_H_
#define HDR_ template <typename LHS, typename RHS, \
						template <typename> class Operation>
#define Expr_ Expr<LHS, RHS, Operation>

#include "trait.h"
#include <functional>	// arithmetic function objects
#include <utility>
#include <iostream>
/*
HDR_
class Expr
{
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
	return Operation<value_type>{}(d_lhs[idx], d_rhs[idx]);
}

HDR_
size_t Expr_::size() const
{
	return d_lhs.size();
}
*/
template <typename LHS>
class Vect: public std::vector<LHS>
{

};

// free binary operators
template <typename LHS>
auto operator+(std::vector<LHS> const &lhs, std::vector<LHS> const &rhs)
{
	std::cout << "operator+() used\n";
	Vect<LHS> ret;
	ret.reserve(lhs.size());
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		ret.push_back(std::plus<LHS>{}( lhs[idx], rhs[idx] ));

	return Vect<LHS>();
}

template <typename LHS>
auto operator+(std::vector<LHS> &&lhs, std::vector<LHS> const &rhs)
{
	std::cout << "operator+(&&) used\n" << lhs.size();

	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		lhs[idx] += rhs[idx];

	return std::move(lhs);
}
/*
template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
	return Expr<LHS, RHS, std::plus>{ lhs, rhs };
}
*/
#undef Expr_
#undef HDR_
#endif