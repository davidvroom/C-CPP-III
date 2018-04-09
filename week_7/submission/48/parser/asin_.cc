#include "parser.ih"

RuleValue &Parser::asin_(RuleValue &e)
{
    return e = asin(angle(valueOf(e)));
}
