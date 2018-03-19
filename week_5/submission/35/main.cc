#include "scanner/scanner.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream file{ argv[1] }; 
	Scanner scanner{ file };
	while (int TOKEN = scanner.lex())
		cout << TOKEN << ' ' << scanner.matched() << '\n';
}
