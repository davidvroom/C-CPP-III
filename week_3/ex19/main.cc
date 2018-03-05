#include <iostream>
#include "convert.h"

using namespace std;

struct OneChar;

ostream &operator<<(ostream &out, OneChar const &obj)
{
	return out << obj.value ;
}

int main()
{
    //cout << int{} << '\n';    // displays '157255'
    cout << Convert<57005, 16>::CP{} << '\n';   // displays 'dead'
    //cout << Convert<57005, 32>::CP{} << '\n';   // displays '1nld'
}
