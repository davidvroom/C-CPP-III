#include <iostream>
#include <vector>
#include "forwarder.h"
#include "demo/demo.h"

using namespace std;

void fun(int first, int second)
{
    cout << "fun(" << first << ", " << second << ")\n";
}

void fun2(Demo &&dem1, Demo &&dem2)
{
    cout << "fun2(dem1, dem2)\n";
}
                                // increments each argument:
void incrementer(int &one, int &two, int &three)
{
    ++one;
    ++two;
    ++three;
}

void fun(Demo &&dem1, Demo &&dem2)
{
    cout << "fun(dem1, dem2)\n";
}

int main()
{
                                // inserts 'fun(dem1, dem2)' to cout
    forwarder<void(Demo &&, Demo &&)>(fun, Demo{}, Demo{});
    
                                // inserts 'fun(1, 3)' to cout
    forwarder<void(int, int)>(fun, 1, 3);  

                                // inserts 'fun2(dem1, dem2)' to cout
    forwarder(fun2, Demo{}, Demo{});

    forwarder(plus<string>(), "hello ", "world");

    vector<int> first;
    forwarder(                  // receives a lambda function
        [](vector<int> &first, vector<int> const &second, vector<int> const &third)
        {
            // modify first's elements using second's and third's
            // elements
        }, first, vector<int>{}, vector<int>{}
    );

    int x = 0;
    forwarder(incrementer, x, x, x);
    cout << x << '\n';          // should show '3'
}