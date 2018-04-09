#include "parser.ih"

RuleValue &Parser::bwOr(RuleValue &lvalue, RuleValue &rvalue)
{
	lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) | static_cast<int>(round(valueOf(rvalue)));
	lvalue.d_type = RuleValue::VALUE;

	return lvalue;
}
