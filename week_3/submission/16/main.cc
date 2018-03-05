#include "type.h"
#include <iostream>

using namespace std;

int main()
{
    cout <<
        Type<int>::located << ' ' << 
        Type<int, double>::located << ' ' << 
    	Type<int, double, double>::located << ' ' << 
        Type<int, int>::located << ' ' << 
        Type<int, int, double>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int, int, int>::located << ' ' <<
        Type<int, double, int, double, int>::located << 
        '\n';
}
        