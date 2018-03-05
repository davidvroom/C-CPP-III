#include <iostream>
#include "convert.h"

using namespace std;

template<char First, char ...Rest>
struct Chars;

template <char First, char ...Rest>
ostream &operator<<(ostream &out, Chars<First, Rest...> const &enm)
{
	return out << char { Chars<First, Rest...>::value }
			   << Chars<Rest... >{};
}

template <char Last>
ostream &operator<<(ostream &out, Chars<Last> const &obj)
{
	return out << char { Chars<Last>::value };
}

int main()
{
    //cout << int{} << '\n';    // displays '157255'
    cout << Convert<57005, 16>::CP{} << '\n';   // displays 'dead'
    //cout << Convert<57005, 32>::CP{} << '\n';   // displays '1nld'
}
