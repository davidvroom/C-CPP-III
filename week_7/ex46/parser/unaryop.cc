#include "parser.ih"

RuleValue Parser::unaryOp(char const unaryOp, RuleValue &value)
{
	switch (unaryOp)
	{
		case '-':
    		value = -valueOf(value);
		break;
		case '~':
			value.d_number = ~static_cast<int>(round(valueOf(value)));
			value.d_type = RuleValue::VALUE;			
		break;		
	}
	
	return value;
}