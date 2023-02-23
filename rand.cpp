#include <sstream>
#include <iostream>
#include "rand.hpp"
using namespace std;

//constructor
Rand::Rand() : Base(), value(rand() % 100)
{}

double Rand::evaluate()
{
	return value;
}

string Rand::stringify()
{
	stringstream ss;
	ss << "{";
	ss << value;
	ss << "}";

	return ss.str();
}

int Rand::number_of_children()
{
	return 0;
}


Base* Rand::get_child(int i)
{
	Base* Op1 = new Rand();
	return Op1;
	/*Base* Op1 = new Op(3);
	return Op1;*/

}
