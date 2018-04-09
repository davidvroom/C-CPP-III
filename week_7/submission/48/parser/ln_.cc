#include "parser.ih"

RuleValue &Parser::ln_(RuleValue &e)
{
    return e = log(valueOf(e));
}
