#include "parser.ih"

RuleValue &Parser::sin_(RuleValue &e)
{
    return e = sin(angle(valueOf(e)));
}
