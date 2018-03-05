#ifndef INCLUDED_BIN_H_
#define INCLUDED_BIN_H_

template <size_t Decimal> 
class Bin
{
	template <size_t sameDecimal, size_t accBin, size_t accDec, size_t idx, 
			  size_t tens, size_t twos>
	struct DetermineBin
	{
		enum { value = DetermineBin<sameDecimal, 
			                        accBin + ((sameDecimal >> idx) & 1) * tens, 
			                        accDec + ((sameDecimal >> idx) & 1) * twos, 
			                        idx + 1, 
			                        tens * 10, 
			                        twos * 2>::value 
			                    };
	};

	public:
		enum { value = DetermineBin<Decimal, 0, 0, 0, 1, 1>::value };
};

template <size_t Decimal> 
template <size_t accBin, size_t idx, size_t tens, size_t twos>
struct Bin<Decimal>::DetermineBin<Decimal, accBin, Decimal, idx, tens, twos>
{
	enum { value = accBin + ((Decimal >> idx) & 1) * tens };
};

#endif

