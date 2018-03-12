#ifndef INCLUDED_BINOPS_H_
#define INCLUDED_BINOPS_H_

#include <vector>
#include <iomanip>

// free binary operators
template <typename Type>
auto operator+(std::vector<Type> const &lhs, std::vector<Type> const &rhs)
{
	std::vector<Type> ret;

	ret.reserve(lhs.size());
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		ret.push_back(lhs[idx] + rhs[idx]);

	return ret;
}

template <typename Type>
auto operator+(std::vector<Type> &&lhs, std::vector<Type> const &rhs)
{
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		lhs[idx] += rhs[idx];

	return std::move(lhs);
}

template <typename Type>
auto operator-(std::vector<Type> const &lhs, std::vector<Type> const &rhs)
{
	std::vector<Type> ret;

	ret.reserve(lhs.size());
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		ret.push_back(lhs[idx] - rhs[idx]);

	return ret;
}

template <typename Type>
auto operator-(std::vector<Type> &&lhs, std::vector<Type> const &rhs)
{
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		lhs[idx] -= rhs[idx];

	return std::move(lhs);
}

template <typename Type>
auto operator*(std::vector<Type> const &lhs, std::vector<Type> const &rhs)
{
	std::vector<Type> ret;

	ret.reserve(lhs.size());
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		ret.push_back(lhs[idx] * rhs[idx]);

	return ret;
}

template <typename Type>
auto operator*(std::vector<Type> &&lhs, std::vector<Type> const &rhs)
{
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		lhs[idx] *= rhs[idx];

	return std::move(lhs);
}

template <typename Type>
auto operator/(std::vector<Type> const &lhs, std::vector<Type> const &rhs)
{
	std::vector<Type> ret;

	ret.reserve(lhs.size());
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		ret.push_back(lhs[idx] / rhs[idx]);

	return ret;
}

template <typename Type>
auto operator/(std::vector<Type> &&lhs, std::vector<Type> const &rhs)
{
	for (size_t idx = 0, end = lhs.size(); idx != end; ++idx)
		lhs[idx] /= rhs[idx];

	return std::move(lhs);
}

#endif