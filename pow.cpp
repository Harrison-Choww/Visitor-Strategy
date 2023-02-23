#include "pow.hpp"

Pow::Pow(Base* one, Base* two) {
    value1 = one->evaluate();
    value2 = two->evaluate();
    Op1 = one;
    Op2 = two;
}

double Pow::evaluate() {
    return pow(value1, value2);
}

string Pow::stringify() {
    return "{(" + Op1->stringify() + "^" + Op2->stringify() + ")}";
}

int Pow::number_of_children()
{
	return 2;
}

Base* Pow::get_child(int i)
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
