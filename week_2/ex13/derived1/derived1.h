#ifndef INCLUDED_DERIVED1_H_
#define INCLUDED_DERIVED1_H_

#include "../abc/abc.h"
#include <ostream>

class Derived1: public ABC
{
    public:
        Derived1(std::ostream &out);
    private:
    	void run() override;
};

#endif