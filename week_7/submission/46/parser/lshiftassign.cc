#include "parser.ih"

RuleValue &Parser::lShiftAssign(RuleValue &lvalue, RuleValue &rvalue)
{
	double result = static_cast<int>(round(valueOf(lvalue))) << static_cast<int>(round(valueOf(rvalue)));
	RuleValue tmp{result};	
	return assign(lvalue, tmp);
}
