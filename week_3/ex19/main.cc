#include <iostream>
#include "convert.h"

using namespace std;

template<char First, char ...Rest>
struct Chars;

char range[] = "0123456789abcdefghijklmnopqrstuvwxyz";

template <char First, char ...Rest>
ostream &operator<<(ostream &out, Chars<First, Rest...> const &obj)
{
	return out << range[Chars<First, Rest...>::value] 
			   << Chars<Rest...>{};
}

template <char Last>
ostream &operator<<(ostream &out, Chars<Last> const &obj)
{
	return out << range[Chars<Last>::value];
}



int main()
{
    cout << Convert<57005, 8>::CP{} << '\n';    // displays '157255'
    cout << Convert<57005, 16>::CP{} << '\n';   // displays 'dead'
    cout << Convert<57005, 32>::CP{} << '\n';   // displays '1nld'
    //cout << Convert<0, 10>::CP{} << '\n';
}
