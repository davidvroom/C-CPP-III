#include "parser.ih"

RuleValue &Parser::mulAssign(RuleValue &lvalue, RuleValue &rvalue)
{
	RuleValue tmp{valueOf(lvalue) * valueOf(rvalue)};
	return assign(lvalue, tmp);
}