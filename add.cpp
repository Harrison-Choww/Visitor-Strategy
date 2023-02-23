#include "add.hpp"
#include <iostream>

Add::Add(Base* one, Base* two) {
    val1 = one->evaluate();
    val2 = two->evaluate();
    Op1 = one;
    Op2 = two;
}

double Add::evaluate() {
    return val1 + val2;
}

string Add::stringify() {
    return "{(" + Op1->stringify() + "+" + Op2->stringify() + ")}";
}

/*string Add::stringifyML() {
    return "    <cn>" + Op1->stringify() + "    </cn>\n" + "<cn>" + Op2->stringify() + "</cn>\n";
}*/

int Add::number_of_children()
{
    return 2;
}

Base* Add::get_child(int i)
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
