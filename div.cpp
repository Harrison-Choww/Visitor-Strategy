#include "div.hpp"

#include <sstream>
using namespace std;

//constructor
Div::Div(Base* Op1, Base* Op2) : Base(), value1(Op1->evaluate()), value2(Op2->evaluate()), Op1(Op1), Op2(Op2)
{}

double Div::evaluate()
{
	if (value2 != 0)
	{
		return value1 / value2;
	}
	return 0.0;
}

string Div::stringify()
{
	stringstream ss;
	ss << "{\\frac";
	ss << Op1->stringify();
	ss << Op2->stringify();
	ss << "}";

	return ss.str();
}

int Div::number_of_children()
{
	return 2;
}

Base* Div::get_child(int i)
{
	if (i == 0)
	{
		return Op1;
	}
	else
	{
		return Op2;
	}
}
