// Why is a minimal match feature not required for flex? 

// This is because flex choose the more complicated implementation; 
// the greedy variant, because by this flex prevents too early and 
// therefore multiple parsing. If for specific cases a non-greedy 
// match is needed, one can make a mini-scanner or use a look-ahead 
// operator together with an end character that is not allowed for 
// the greedy match.

#include "main.ih"

int main()
try
{
	Scanner scanner;

	while (scanner.lex())
		;
}
catch (...)
{
	return 1;
}
