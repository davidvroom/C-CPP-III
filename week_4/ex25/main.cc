#include <vector>
#include <deque>
#include <string>
#include <iostream>

#include "insertable.h"

using namespace std;

int main()
{
    deque<string> ds{ "kilo", "lima", "mike" };

    vector<int> vi{ 1, 2, 3, 4, 5 };

    int four = 4;

    Insertable<vector, int> iv;
    Insertable<vector, int> iv2(vi);
    //Insertable<vector, int> iv2(std::move(vi));
    //Insertable<vector, int> iv3(4);
    Insertable<vector, int> iv3(four);
    //Insertable<vector, int> iv3(int{4});
    Insertable<vector, int> iv4(iv2);

    cout << iv2 << '\n' 
         << iv3 << '\n' 
         << iv4 << '\n';

    iv3.push_back(123);
    cout << iv3 << '\n';

    Insertable<deque, string> sd(ds);
    sd.push_back("november");

    cout << "sd has " 
         << sd.size() 
         << " elements and contains:\n"
         << sd << '\n';
}