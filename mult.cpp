#include <sstream>
#include "mult.hpp"
using namespace std;

//constructor
Mult::Mult(Base* Op1, Base* Op2) : Base(), value1(Op1->evaluate()), value2(Op2->evaluate()), Op1(Op1), Op2(Op2)
{}

double Mult::evaluate()
{
	return value1 * value2;
}

string Mult::stringify()
{
	stringstream ss;
	ss << "{(";
	ss << Op1->stringify();
	ss << "\\cdot";
	ss << Op2->stringify();
	ss << ")}";

	return ss.str();
}

int Mult::number_of_children()
{
	return 2;
}

Base* Mult::get_child(int i)
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
