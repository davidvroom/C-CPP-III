#include "storage.h"
#include <string>
#include <algorithm>

#include <iostream>

int main()
{
    Storage<std::string> storage;

    sort(storage.begin(), storage.end());
    std::cout << *storage.begin() << ' '
    	 << *++storage.begin() << ' '
    	 << *++++storage.begin() << '\n';

    sort(storage.rbegin(), storage.rend());
    std::cout << *storage.begin() << ' '
    	 << *++storage.begin() << ' '
    	 << *++++storage.begin() << '\n';
}

