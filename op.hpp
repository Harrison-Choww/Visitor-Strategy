#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include <string>
#include <iostream>
using namespace std;

class Op : public Base {
public:
    Op(double value);
    virtual double evaluate();
    virtual std::string stringify();
    virtual int number_of_children();
    virtual Base* get_child(int i);
    void accept(Visitor* visitor, int index) override {
        cout << "index: " << index << endl;
        visitor->visit_op(this);
    }

private:
    double value;

};

#endif //__OP_HPP__
