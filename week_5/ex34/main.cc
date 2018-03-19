#include "scanner/scanner.h"

using namespace std;

int main(int argc, char **argv)
{
	Scanner scanner{ argv[1] };	
	scanner.lex();
	scanner.finish();
}
