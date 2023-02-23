#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>

class Div : public Base {
public:
    Div(Base* Op1, Base* Op2);
    virtual double evaluate();
    virtual std::string stringify();
    virtual int number_of_children();
    virtual Base* get_child(int i);
    void accept(Visitor* visitor, int index) override {
        if (index == 0)
        {
            visitor->visit_div_begin(this);
        }
        else if (index == 1)
        {
            visitor->visit_div_middle(this);
        }
        else
        {
            visitor->visit_div_end(this);
        }
    }


private:
    double value1;
    double value2;
    Base* Op1;
    Base* Op2;

};

#endif //Div_hpp
