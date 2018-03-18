#include "expr.h"
#include <vector>
#include <iostream>

int main()
{
    typedef std::vector<int> IVect;
    IVect iv1(1000000, 4);        
    IVect iv2(1000000, 3);
    IVect iv3(1000000, 2);
    IVect iv4(1000000, 2);

    IVect iResult{ iv1 + iv2 + iv3 + iv4 };

    /*
    IVect tmp;
    tmp.reserve(iv1.size());
    for (size_t idx = 0, end = iv1.size(); idx != end; ++idx)
    {
        tmp[idx] = iv1[idx] + iv2[idx];
    }

    IVect tmp2;
    tmp2.reserve(iv1.size());
    for (size_t idx = 0, end = iv1.size(); idx != end; ++idx)
    {
        tmp2[idx] = tmp[idx] + iv3[idx];
    }

    IVect tmp3;
    tmp3.reserve(iv1.size());
    for (size_t idx = 0, end = iv1.size(); idx != end; ++idx)
    {
        tmp3[idx] = tmp2[idx] + iv4[idx];
    }
    */
}
