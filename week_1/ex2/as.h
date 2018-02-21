#ifndef INCLUDED_AS_
#define INCLUDED_AS_

template <typename newType, typename oldType>
newType as(oldType &&value)
{
	return static_cast<newType>(value);
}

#endif 
