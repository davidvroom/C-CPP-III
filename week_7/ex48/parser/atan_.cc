#include "parser.ih"

RuleValue &Parser::atan_(RuleValue &e)
{
    return e = atan(angle(valueOf(e)));
}
