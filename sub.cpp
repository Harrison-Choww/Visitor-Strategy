#include "sub.hpp"

Sub::Sub(Base* one, Base* two) {
    value1 = one->evaluate();
    value2 = two->evaluate();
    Op1 = one;
    Op2 = two;
}

double Sub::evaluate() {
    return value1 - value2;
}

string Sub::stringify() {
    return "{(" + Op1->stringify() + "-" + Op2->stringify() + ")}";
}

int Sub::number_of_children()
{
	return 2;
}

Base* Sub::get_child(int i)
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
