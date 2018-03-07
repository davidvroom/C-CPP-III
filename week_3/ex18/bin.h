#ifndef INCLUDED_BIN_H_
#define INCLUDED_BIN_H_

#include <cstddef>

template <size_t Decimal, 
		  size_t accBin = 0, 
		  size_t accDec = 0, 
		  size_t idx = 0, 
		  size_t tens = 1, 
		  size_t twos = 1>
struct Bin
{
	enum { value = Bin<Decimal, 
				       accBin + ((Decimal >> idx) & 1) * tens, 
				       accDec + ((Decimal >> idx) & 1) * twos, 
				       idx + 1, 
				       tens * 10, 
				       twos * 2>::value 
	     };
};

template <size_t Decimal, 
	      size_t accBin, 
	      size_t idx, 
	      size_t tens, 
	      size_t twos>
struct Bin<Decimal, accBin, Decimal, idx, tens, twos>
{
	enum { value = accBin + ((Decimal >> idx) & 1) * tens };
};

#endif
