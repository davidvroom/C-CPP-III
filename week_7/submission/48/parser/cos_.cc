#include "parser.ih"

RuleValue &Parser::cos_(RuleValue &e)
{
    return e = cos(angle(valueOf(e)));
}
