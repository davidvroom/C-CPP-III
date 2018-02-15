#include <iostream>
#include "storage/storage.h"
#include "enumclasses.h"

using namespace std;

int main()
{
	Storage storage{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

    cout << storage[Icmp::ID]           << '\n' <<
            storage[TcpUdp::PROTOCOL]   << '\n' <<
            storage[12]                 << '\n' <<
            storage['a']                << '\n' <<
            storage[12.5]               << '\n';        
}