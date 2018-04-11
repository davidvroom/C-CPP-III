#ifndef INCLUDED_FUNCTIONMAP_H_
#define INCLUDED_FUNCTIONMAP_H_

#include <map>
#include <string>

class FunctionMap: public std::map<std::string, double (*)(double)>
{
	public:
		FunctionMap();
};

#endif