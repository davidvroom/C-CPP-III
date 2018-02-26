#include "process/process.h"
#include "derived1/derived1.h"
#include "derived2/derived2.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    Process process{
                argc == 1 ? static_cast<ABC &&>(Derived1{ cerr }) : 
                			static_cast<ABC &&>(Derived2{ cin, cout })
            };
    // etc.
}
