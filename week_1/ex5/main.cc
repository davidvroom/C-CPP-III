#include "main.ih"

void fun(int first, int second)
{
    cout << "fun(" << first << ", " << second << ")\n";
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
}
