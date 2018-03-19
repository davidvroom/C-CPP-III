#include "scanner/scanner.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
					// replace NTBS by argv[1], but this is easier for testing
	Scanner scanner{"input.txt"};	
	scanner.lex();
	scanner.finish();
}