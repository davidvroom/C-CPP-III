#include "scanner.ih"

void Scanner::initializeFunctionMap()
{
	pair<string, double (*)(double)> pa[] = 
	{
		pair<string, double (*)(double)>("exp", exp),
		pair<string, double (*)(double)>("ln", log),
		pair<string, double (*)(double)>("sin", sin)
	};

	d_functionMap.insert(&pa[0], &pa[3]);
}
