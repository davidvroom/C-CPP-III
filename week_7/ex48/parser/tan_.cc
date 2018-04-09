#include "parser.ih"

RuleValue &Parser::tan_(RuleValue &e)
{
	return e = tan(angle(valueOf(e)));
}
