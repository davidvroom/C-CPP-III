#include "parser.ih"

double Parser::angle(double const inputAngle)
{
	return d_angle == RAD ? inputAngle :
		   d_angle == DEG ? inputAngle * 3.1415926535 / 180 :
		   inputAngle * 3.1415926535 / 200;
}