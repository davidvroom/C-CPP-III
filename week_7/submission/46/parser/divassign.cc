#include "parser.ih"

RuleValue &Parser::divAssign(RuleValue &lvalue, RuleValue &rvalue)
{
	RuleValue tmp{valueOf(lvalue) / valueOf(rvalue)};
	return assign(lvalue, tmp);
}