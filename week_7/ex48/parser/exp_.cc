#include "parser.ih"

RuleValue &Parser::exp_(RuleValue &e)
{
    return e = exp(valueOf(e));
}
