#ifndef	INCLUDED_POINTERUNION_
#define INCLUDED_POINTERUNION_

union PointerUnion
{
	int (*fp)(int const &, int const &);
	void *vp;
};

#endif