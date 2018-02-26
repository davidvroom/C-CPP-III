#include "data/data.h"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
	Data data;
	
	string strArr[1];
	while (getline(cin, strArr[0]))
		copy(strArr, strArr + 1, back_inserter(data));
}