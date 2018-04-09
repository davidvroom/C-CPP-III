#include "parser.ih"

RuleValue &Parser::abs_(RuleValue &e)
{
    return e = abs(valueOf(e));
}
