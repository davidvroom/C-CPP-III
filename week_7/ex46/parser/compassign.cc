#include "parser.ih"

RuleValue Parser::compAssign(RuleValue &lvalue, char const binaryOp, RuleValue &rvalue)
{
	RuleValue tmp;

	switch (binaryOp)
	{
		case '+':
			tmp = valueOf(lvalue) + valueOf(rvalue);
		break;
		case '-':
			tmp = valueOf(lvalue) - valueOf(rvalue);
		break;		
		case '*':
			tmp = valueOf(lvalue) * valueOf(rvalue);
		break;
		case '/':
			tmp = valueOf(lvalue) / valueOf(rvalue);
		break;		
		case '%':
			tmp = static_cast<double>(static_cast<int>(round(valueOf(lvalue))) % static_cast<int>(round(valueOf(rvalue))));
		break;
		case '&':
			tmp = static_cast<double>(static_cast<int>(round(valueOf(lvalue))) & static_cast<int>(round(valueOf(rvalue))));
		break;
		case '|':
			tmp = static_cast<double>(static_cast<int>(round(valueOf(lvalue))) | static_cast<int>(round(valueOf(rvalue))));
		break;
		case '^':
			tmp = static_cast<double>(static_cast<int>(round(valueOf(lvalue))) ^ static_cast<int>(round(valueOf(rvalue))));
		break;		
		case '<':
			tmp = static_cast<double>(static_cast<int>(round(valueOf(lvalue))) << static_cast<int>(round(valueOf(rvalue))));
		break;
		case '>':
			tmp = static_cast<double>(static_cast<int>(round(valueOf(lvalue))) >> static_cast<int>(round(valueOf(rvalue))));
		break;	
	}

	return assign(lvalue, tmp);
}