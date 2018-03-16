#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include "scanner/scanner.h"

using namespace std;

int main(int argc, char **argv)
{
	set<string> container;

	Scanner scanner;

	if (argc > 1)
		for (;argc-- != 1;)
		{
			ifstream file{ argv[argc] };
			scanner.switchStreams(file);
			while (scanner.lex())
				container.insert(scanner.matched());
		}

	else
	{
		while (scanner.lex())
			container.insert(scanner.matched());
	}

	for (auto iter = container.begin(), end = container.end(); iter != end; ++iter)
		cout << *iter << '\n'; 
}
