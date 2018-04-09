#include "parser.ih"

RuleValue &Parser::sqrt_(RuleValue &e)
{
    return e = sqrt(valueOf(e));
}
