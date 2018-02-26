#ifndef INCLUDED_DERIVED2_H_
#define INCLUDED_DERIVED2_H_

#include "../abc/abc.h"
#include <istream>
#include <ostream>

class Derived2: public ABC
{
    public:
        Derived2(std::istream &in, std::ostream &out);
    private:
    	void run() override;
};

#endif