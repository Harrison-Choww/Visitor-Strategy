#ifndef __PRINTLATEx_HPP__
#define __PRINTLATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include <iostream>

class printLaTex : public Visitor
{
public:
    ~printLaTex() {}
    string temp = "";

    void visit_op(Op* Op1)
    {
        std::cout << "Op visited." << std::endl;
        cout << "{" + Op1->stringify() + "}";
    }

    void visit_rand(Rand* Random)
    {
        std::cout << "Rand visited." << std::endl;
        cout << "{" + Random->stringify() + "}";
    }

    void visit_add_begin(Add* node)
    {
        std::cout << "Add begin visited." << std::endl;
        temp = "${(" + node->get_child(0)->stringify();
    }

    void visit_add_middle(Add* node)
    {
        std::cout << "Add middle visited." << std::endl;
        temp = temp + "+";
    }

    void visit_add_end(Add* node)
    {
        std::cout << "Add end visited." << std::endl;
        temp = temp + node->get_child(1)->stringify() + ")}$";
        cout << temp << endl;
    }

    void visit_sub_begin(Sub* node)
    {
        std::cout << "Sub begin visited." << std::endl;
        temp = "${(" + node->get_child(0)->stringify();
    }

    void visit_sub_middle(Sub* node)
    {
        std::cout << "Sub middle visited." << std::endl;
        temp = temp + "-";
    }

    void visit_sub_end(Sub* node)
    {
        std::cout << "Sub end visited." << std::endl;
        temp = temp + node->get_child(1)->stringify() + ")}$";
        cout << temp << endl;
    }

    void visit_mult_begin(Mult* node)
    {
        std::cout << "Mult begin visited." << std::endl;
        temp = "${(" + node->get_child(0)->stringify();
    }

    void visit_mult_middle(Mult* node)
    {
        std::cout << "Mult middle visited." << std::endl;
        temp = temp + "\\cdot";
    }

    void visit_mult_end(Mult* node)
    {
        std::cout << "Mult end visited." << std::endl;
        temp = temp + node->get_child(1)->stringify() + ")}$";
        cout << temp << endl;
    }

    void visit_div_begin(Div* node)
    {
        std::cout << "Div begin visited." << std::endl;
        temp = node->get_child(0)->stringify();
    }

    void visit_div_middle(Div* node)
    {
        std::cout << "Div middle visited." << std::endl;
        temp = "${\\frac" + temp;
    }

    void visit_div_end(Div* node)
    {
        std::cout << "Div end visited." << std::endl;
        temp = temp + node->get_child(1)->stringify() + "}$";
        cout << temp << endl;
    }

    void visit_pow_begin(Pow* node)
    {
        std::cout << "Pow begin visited." << std::endl;
        temp = "${(" + node->get_child(0)->stringify();
    }

    void visit_pow_middle(Pow* node)
    {
        std::cout << "Pow middle visited." << std::endl;
        temp = temp + "^";
    }

    void visit_pow_end(Pow* node)
    {
        std::cout << "Pow end visited." << std::endl;
        temp = temp + node->get_child(1)->stringify() + ")}$";
        cout << temp << endl;
    }
};


#endif //__PRINTLATEX_HPP__
