#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <string>

class Mult : public Base {
public:
    Mult(Base* Op1, Base* Op2);
    virtual double evaluate();
    virtual std::string stringify();
    virtual int number_of_children();
    virtual Base* get_child(int i);
    void accept(Visitor* visitor, int index) override {
        if (index == 0)
        {
            visitor->visit_mult_begin(this);
        }
        else if (index == 1)
        {
            visitor->visit_mult_middle(this);
        }
        else
        {
            visitor->visit_mult_end(this);
        }
    }


private:
    double value1;
    double value2;
    Base* Op1;
    Base* Op2;

};

#endif //mult_hpp
