#include <iostream>
#include <fstream>
#include "scanner/scanner.h"

#include <string>
using namespace std;

int main(int argc, char **argv)
{
	fstream file("main.cc");
	Scanner scanner(file);
	while (scanner.lex())
		;
}
