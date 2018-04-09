#include "parser.ih"

void Parser::process(STYPE__ &semVal) const
{
	if (semVal.tag() == Tag__::INT)
		cout << "Saw int: " << semVal.get<Tag__::INT>() << '\n';
    else if (semVal.tag() == Tag__::STRING)
        cout << "Saw string: " << semVal.get<Tag__::STRING>() << '\n'; 
    else
        cout << "Saw double: " << semVal.get<Tag__::DOUBLE>() << '\n';
}