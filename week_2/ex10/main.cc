#include "data/data.h"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
	Data data;
	
	//data.push_back("test");
	
	/*string arr[] = {string("test")};

	copy(arr, arr + 1, back_inserter(data));
	cout << data.get(0) << '\n';
	*/

	string strArr[1];
	while (getline(cin, strArr[0]))
		copy(strArr, strArr + 1, back_inserter(data));
	

	cout << data.get(0) << '\n';


	/*copy(istream_iterator<string>(cin), istream_iterator<string>(),
		 back_inserter(data));
	cout << data.get(0) << '\n';
	*/

}