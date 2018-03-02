#ifndef INCLUDED_STORAGE_H
#define INCLUDED_STORAGE_H

#include "inttype.h"
#include "ifelse.h"
#include <vector>

template <typename Type, bool isPolymorphic>
class Storage
{
	typedef typename IfElse<isPolymorphic, Type *, Type>::type
			DataType;
	std::vector<DataType> d_data;
	private:
		void add(Type const &obj, IntType<true>);
		void add(Type const &obj, IntType<false>);
	public:
		void add(Type const &obj);
};

template <typename Type, bool isPolymorphic>
void Storage<Type, isPolymorphic>::add(Type const &obj, IntType<true>)
{
	d_data.push_back(obj.clone());
}

template <typename Type, bool isPolymorphic>
void Storage<Type, isPolymorphic>::add(Type const &obj, IntType<false>)
{
	d_data.push_back(obj);
}

template <typename Type, bool isPolymorphic>
void Storage<Type, isPolymorphic>::add(Type const &obj)
{
	add(obj, IntType<isPolymorphic>());
}

#endif