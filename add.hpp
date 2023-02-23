#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Add : public Base {
public:
    Add(Base* one, Base* two);
    virtual double evaluate();
    virtual string stringify();
    virtual int number_of_children();
    virtual Base* get_child(int i);
    void accept(Visitor* visitor, int index) override {
        if (index == 0)
        {
            visitor->visit_add_begin(this);
        }
        else if (index == 1)
        {
            visitor->visit_add_middle(this);
        }
        else
        {
            visitor->visit_add_end(this);
        }
    }

private:
    double val1;
    double val2;
    Base* Op1;
    Base* Op2;
};

#endif
