#include "parser.ih"

RuleValue &Parser::bwNot(RuleValue &lvalue)
{
	lvalue.d_number = ~static_cast<int>(round(valueOf(lvalue)));
	lvalue.d_type = RuleValue::VALUE;

	return lvalue;
}
