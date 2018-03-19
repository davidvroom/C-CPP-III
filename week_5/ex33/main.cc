#include <fstream>
#include "scanner/scanner.h"

using namespace std;

int main()
{
	ifstream file{ "text.txt" };
	Scanner scanner{ file };
	while (scanner.lex())
		;
}
