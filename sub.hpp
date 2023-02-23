#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Sub : public Base {
public:
    Sub(Base* one, Base* two);
    virtual double evaluate();
    virtual string stringify();
    virtual int number_of_children();
    virtual Base* get_child(int i);
    void accept(Visitor* visitor, int index) override {
        if (index == 0)
        {
            visitor->visit_sub_begin(this);
        }
        else if (index == 1)
        {
            visitor->visit_sub_middle(this);
        }
        else
        {
            visitor->visit_sub_end(this);
        }
    }

private:
    double value1;
    double value2;
    Base* Op1;
    Base* Op2;

};

#endif
