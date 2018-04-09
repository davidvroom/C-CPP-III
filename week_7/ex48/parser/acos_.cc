#include "parser.ih"

RuleValue &Parser::acos_(RuleValue &e)
{
    return e = acos(angle(valueOf(e)));
}
