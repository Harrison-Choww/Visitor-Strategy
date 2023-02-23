#ifndef __PRINTLT_HPP__
#define __PRINTLT_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include <iostream>
#include <string>
using namespace std;

class printLT : public Visitor
{
public:
    ~printLT() {}
    string tempLT = "$";
    int visit = 0;

    void visit_op(Op* Op1)
    {
        string tempStr = Op1->stringify();
        int tempLen = tempStr.length();
        tempLT = tempLT + "{" + tempStr.substr(1, tempLen - 2) + "}";
    }

    void visit_rand(Rand* Random)
    {
        string tempStr = Random->stringify();
        int tempLen = tempStr.length();
        tempLT = tempLT + tempStr.substr(1, tempLen - 2);
    }

    void visit_add_begin(Add* node)
    {
        visit++;
        tempLT = tempLT + "{(";
    }

    void visit_add_middle(Add* node)
    {
        tempLT = tempLT + "+";
    }

    void visit_add_end(Add* node)
    {
        if (visit == 1)
        {
            tempLT = tempLT + ")}$";
            cout << tempLT << endl;
            tempLT = "$";
            visit = 0;
        }
        else
        {
            tempLT = tempLT + ")}";
            visit--;
        }
    }

    void visit_sub_begin(Sub* node)
    {
        visit++;
        tempLT = tempLT + "{(";
    }

    void visit_sub_middle(Sub* node)
    {
        tempLT = tempLT + "-";
    }

    void visit_sub_end(Sub* node)
    {
        if (visit == 1)
        {
            tempLT = tempLT + ")}$";
            cout << tempLT << endl;
            tempLT = "$";
            visit = 0;
        }
        else
        {
            tempLT = tempLT + ")}";
            visit--;
        }
    }

    void visit_mult_begin(Mult* node)
    {
        visit++;
        tempLT = tempLT + "{(";
    }

    void visit_mult_middle(Mult* node)
    {
        tempLT = tempLT + "\\cdot";
    }

    void visit_mult_end(Mult* node)
    {
        if (visit == 1)
        {
            tempLT = tempLT + ")}$";
            cout << tempLT << endl;
            tempLT = "$";
            visit = 0;
        }
        else
        {
            tempLT = tempLT + ")}";
            visit--;
        }
    }

    void visit_div_begin(Div* node)
    {
        visit++;
        tempLT = tempLT + "{\\frac";
    }

    void visit_div_middle(Div* node)
    {
    }

    void visit_div_end(Div* node)
    {
        if (visit == 1)
        {
            tempLT = tempLT + "}$";
            cout << tempLT << endl;
            tempLT = "$";
            visit = 0;
        }
        else
        {
            tempLT = tempLT + ")}";
            visit--;
        }
    }

    void visit_pow_begin(Pow* node)
    {
        visit++;
        tempLT = tempLT + "{(";
    }

    void visit_pow_middle(Pow* node)
    {
        tempLT = tempLT + "^";
    }

    void visit_pow_end(Pow* node)
    {
        if (visit == 1)
        {
            tempLT = tempLT + ")}$";
            cout << tempLT << endl;
            tempLT = "$";
            visit = 0;
        }
        else
        {
            tempLT = tempLT + ")}";
            visit--;
        }
    }
};


#endif //__PRINTML_HPP__
