#include <sstream>
#include "op.hpp"
#include <iostream>
using namespace std;

//constructor
Op::Op(double value) : Base(), value(value)
{}

double Op::evaluate()
{
	return value;
}

string Op::stringify()
{
	stringstream ss;
	//ss << value;

	ss << "{";
	ss << value;
	ss << "}";

	return ss.str();
}

int Op::number_of_children()
{
	return 0;
}

Base* Op::get_child(int i)
{
	Base* Op1 = new Op(value);
	return Op1;
}
