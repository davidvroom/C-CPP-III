#include "parser.ih"

RuleValue &Parser::addAssign(RuleValue &lvalue, RuleValue &rvalue)
{
	RuleValue tmp{valueOf(lvalue) + valueOf(rvalue)};
	return assign(lvalue, tmp);
}