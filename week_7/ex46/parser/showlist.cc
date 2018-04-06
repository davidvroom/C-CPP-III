#include "parser.ih"

void Parser::showList()
{
	map<string, unsigned> sortedMap{d_symtab.begin(), d_symtab.end()};

	for (auto iter = sortedMap.begin(), end = sortedMap.end(); 
		 iter != end; 
		 ++iter)
		cout << iter->first << '\t' << d_value[iter->second] << '\n';

	prompt();
}