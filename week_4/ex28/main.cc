#include "expr.h"
#include <vector>
#include <iostream>

typedef std::vector<int> IVect;


int main()
{
        IVect iv1(10, 4);        
        IVect iv2(10, 3);
        IVect iv3(10, 2);
        IVect iv4(10, 1);

        IVect iResult { iv1 + iv2 + iv3};
        std::cout << iv1.size() << '\n';

    for (size_t idx = 0, end = iv1.size(); idx != end; ++idx)
        std::cout << iResult[idx] << '\n';

}


/*
int main()
{
    typedef std::vector<int> IVect;
    IVect iv1(10, 4);        
    IVect iv2(10, 3);
    IVect iv3(10, 2);
    IVect iv4(10, 1);

    IVect iResult { iv1 * (iv2 + iv3) / iv4 };

    for (size_t idx = 0, end = iv1.size(); idx != end; ++idx)
        std::cout << iResult[idx] << '\n';
    
    typedef std::vector<double> DVect;
    DVect dv1(10, 4.1);
    DVect dv2(10, 3.1);
    DVect dv3(10, 2.1);
    DVect dv4(10, 1.1);

    DVect dResult { dv1 * (dv2 + dv3) / dv4 };
    
    for (size_t idx = 0, end = dv1.size(); idx != end; ++idx)
        std::cout << dResult[idx] << '\n';
}
*/
