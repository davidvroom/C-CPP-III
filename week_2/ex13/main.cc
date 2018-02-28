#include "process/process.h"
#include "derived1/derived1.h"
#include "derived2/derived2.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // part 1
    Process process{
                argc == 1 ? 
                static_cast<ABC &&>(Derived1{ cerr }) : 
                static_cast<ABC &&>(Derived2{ cin, cout })
            };
    // etc.

    // part 2
    Process process2{
                argc == 1 ? 
				ABC::make<Derived1>(cerr) : 
                ABC::make<Derived2>(cin, cout)
            };
    // etc.
}
