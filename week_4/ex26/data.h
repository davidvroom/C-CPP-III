#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <cstddef>
#include "traits.h"
#include <vector>
#include <string>

class Data
{
    std::vector<std::string> d_data = {"alpha", "12", "1.24", "delta"};
    
    public:
    	template <typename Type>
    	typename Traits<Type>::ReturnType get(size_t idx) const;

    	//template <>
    	//std::string const &get<std::string>(size_t idx) const;

};

template <typename Type>
typename Traits<Type>::ReturnType Data::get(size_t idx) const
{
	return d_data[idx];
	//Type(d_data[idx]);
	//int("20");

}


/*
template <typename Type, typename ReturnType, bool isclass> // case is class
ReturnType Data::get<Type, isClass>(size_t idx)
{
	return Type const &{ d_data[idx] };
}
*/

#endif