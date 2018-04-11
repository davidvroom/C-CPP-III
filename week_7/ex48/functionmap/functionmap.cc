#include "functionmap.ih"

FunctionMap::FunctionMap()
{
	pair<string, double (*)(double)> pa[] = 
	{
		pair<string, double (*)(double)>("exp", exp),
		pair<string, double (*)(double)>("ln", log),
		pair<string, double (*)(double)>("sin", sin),
		pair<string, double (*)(double)>("asin", asin),
		pair<string, double (*)(double)>("cos", cos),
		pair<string, double (*)(double)>("tan", tan),
		pair<string, double (*)(double)>("atan", atan),
		pair<string, double (*)(double)>("sqrt", sqrt),
		pair<string, double (*)(double)>("abs", abs)
	};

	insert(&pa[0], &pa[9]);
}
