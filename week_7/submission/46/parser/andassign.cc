#include "parser.ih"

RuleValue &Parser::andAssign(RuleValue &lvalue, RuleValue &rvalue)
{
	double result = static_cast<int>(round(valueOf(lvalue))) & static_cast<int>(round(valueOf(rvalue)));
	RuleValue tmp{result};
	return assign(lvalue, tmp);
}
