#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <random>
#include <iostream>
using namespace std;

class Rand : public Base {
public:
    Rand();
    virtual double evaluate();
    virtual std::string stringify();
    virtual int number_of_children();
    virtual Base* get_child(int i);
    void accept(Visitor* visitor, int index) override {
        cout << "index: " << index << endl;
        visitor->visit_rand(this);
    }

private:
    double value;

};

#endif //rand_hpp
