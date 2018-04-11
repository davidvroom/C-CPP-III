#include "parser.ih"

RuleValue Parser::callFunction(string const &str, RuleValue &value)
{
	double result = (d_functionMap[str])(valueOf(value));

	return RuleValue{ result };
}
