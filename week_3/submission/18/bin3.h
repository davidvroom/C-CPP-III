#ifndef INCLUDED_BIN_H_
#define INCLUDED_BIN_H_

template <size_t Decimal, size_t accBin, size_t accDec, size_t idx, size_t tens, size_t twos>
struct DecimalBin
{
	enum { value = DecimalBin<Decimal, accBin + ((Decimal >> idx) & 1) * tens, accDec + ((Decimal >> idx) & 1) * twos, idx + 1, tens * 10, twos * 2>::value };
};

template <size_t Decimal, size_t accBin, size_t idx, size_t tens, size_t twos>
struct DecimalBin<Decimal, accBin, Decimal, idx, tens, twos>
{
	enum { value = accBin + ((Decimal >> idx) & 1) * tens };
};

template <size_t Decimal> 
struct Bin
{
	enum { value = DecimalBin<Decimal, 0, 0, 0, 1, 1>::value };
};

#endif

// value = ((Decimal << 0) & 1) * 1 + 
// 	    ((Decimal << 1) & 1) * 10 + 
// 	    ((Decimal << 2) & 1) * 100 + 
// 	    ((Decimal << 3) & 1) * 1000



