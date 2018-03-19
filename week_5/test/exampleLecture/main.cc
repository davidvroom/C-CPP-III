#include <iostream>
#include <fstream>
#include "scanner/scanner.h"
using namespace std;

int main(int argc, char **argv)
{
	Scanner scanner;
	while (true)
	{
		switch (scanner.lex())
		{
			case 0:
				return 0;
			case NUMBER:
				cout << "Number: " << scanner.matched();
			break;
			case IDENT:
				cout << "Ident: " << scanner.matched();
			break;
			default:
				cout << "Char: " << scanner.matched();
			break;
		}
	}
}
