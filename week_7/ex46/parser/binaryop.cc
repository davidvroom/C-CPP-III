#include "parser.ih"

RuleValue Parser::binaryOp(RuleValue &lvalue, char const binaryOp, RuleValue &rvalue)
{
	switch (binaryOp)
	{
		case '+':
			lvalue.d_number = valueOf(lvalue) + valueOf(rvalue);
		break;
		case '-':
			lvalue.d_number = valueOf(lvalue) - valueOf(rvalue);
		break;		
		case '*':
			lvalue.d_number = valueOf(lvalue) * valueOf(rvalue);
		break;
		case '/':
			lvalue.d_number = valueOf(lvalue) / valueOf(rvalue);
		break;		
		case '%':
			lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) % static_cast<int>(round(valueOf(rvalue)));
		break;
		case '&':
			lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) & static_cast<int>(round(valueOf(rvalue)));
		break;
		case '|':
			lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) | static_cast<int>(round(valueOf(rvalue)));
		break;
		case '^':
			lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) ^ static_cast<int>(round(valueOf(rvalue)));
		break;
		case '<':
			lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) << static_cast<int>(round(valueOf(rvalue)));
		break;
		case '>':
			lvalue.d_number = static_cast<int>(round(valueOf(lvalue))) >> static_cast<int>(round(valueOf(rvalue)));
		break;
	}

	lvalue.d_type = RuleValue::VALUE;

    return lvalue;
}