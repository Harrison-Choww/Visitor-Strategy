#ifndef __PRINTML_HPP__
#define __PRINTML_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include <iostream>
#include <string>
using namespace std;

class printML : public Visitor
{
public:
    ~printML() {}
    string temp = "<math>\n";
    int visit = 0;

    void visit_op(Op* Op1)
    {
        std::cout << "Op visited." << std::endl;
        string tempStr = Op1->stringify();
        int tempLen = tempStr.length();
        //temp = temp + "  ";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<cn>" + tempStr.substr(1, tempLen -2) + "</cn>\n";
    }

    void visit_rand(Rand* Random)
    {
        std::cout << "Rand visited." << std::endl;
        string tempStr = Random->stringify();
        int tempLen = tempStr.length();
        //temp = temp + "  ";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<cn>" + tempStr.substr(1, tempLen - 2) + "</cn>\n";
    }

    void visit_add_begin(Add* node)
    {
        std::cout << "Add begin visited." << std::endl;
        visit++;
        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<apply>\n";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<plus/>\n";

    }

    void visit_add_middle(Add* node)
    {
        std::cout << "Add middle visited." << std::endl;
    }

    void visit_add_end(Add* node)
    {
        std::cout << "Add end visited." << std::endl;
        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        if (visit == 1)
        {
            temp = temp + "</apply>\n</math>";
            cout << temp << endl;
            temp = "<math>\n";
            visit = 0;
        }
        else
        {
            temp = temp + "</apply>\n";
            visit--;
        }
    }

    void visit_sub_begin(Sub* node)
    {
        std::cout << "Sub begin visited." << std::endl;

        visit++;
        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<apply>\n";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<minus/>\n";
    }

    void visit_sub_middle(Sub* node)
    {
        std::cout << "Sub middle visited." << std::endl;
    }

    void visit_sub_end(Sub* node)
    {
        std::cout << "Sub end visited." << std::endl;

        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        if (visit == 1)
        {
            temp = temp + "</apply>\n</math>";
            cout << temp << endl;
            temp = "<math>\n";
            visit = 0;
        }
        else
        {
            temp = temp + "</apply>\n";
            visit--;
        }
    }

    void visit_mult_begin(Mult* node)
    {
        std::cout << "Mult begin visited." << std::endl;

        visit++;
        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<apply>\n";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<times/>\n";
    }

    void visit_mult_middle(Mult* node)
    {
        std::cout << "Mult middle visited." << std::endl;

    }

    void visit_mult_end(Mult* node)
    {
        std::cout << "Mult end visited." << std::endl;

        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        if (visit == 1)
        {
            temp = temp + "</apply>\n</math>";
            cout << temp << endl;
            temp = "<math>\n";
            visit = 0;
        }
        else
        {
            temp = temp + "</apply>\n";
            visit--;
        }
    }

    void visit_div_begin(Div* node)
    {
        std::cout << "Div begin visited." << std::endl;

        visit++;
        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<apply>\n";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<divide/>\n";
    }

    void visit_div_middle(Div* node)
    {
        std::cout << "Div middle visited." << std::endl;
    }

    void visit_div_end(Div* node)
    {
        std::cout << "Div end visited." << std::endl;

        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        if (visit == 1)
        {
            temp = temp + "</apply>\n</math>";
            cout << temp << endl;
            temp = "<math>\n";
            visit = 0;
        }
        else
        {
            temp = temp + "</apply>\n";
            visit--;
        }
    }

    void visit_pow_begin(Pow* node)
    {
        std::cout << "Pow begin visited." << std::endl;

        visit++;
        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<apply>\n";
        for (int i = 0; i <= visit; i++)
        {
            temp = temp + "  ";
        }
        temp = temp + "<power/>\n";
    }

    void visit_pow_middle(Pow* node)
    {
        std::cout << "Pow middle visited." << std::endl;
    }

    void visit_pow_end(Pow* node)
    {
        std::cout << "Pow end visited." << std::endl;

        for (int i = 0; i < visit; i++)
        {
            temp = temp + "  ";
        }
        if (visit == 1)
        {
            temp = temp + "</apply>\n</math>";
            cout << temp << endl;
            temp = "<math>\n";
            visit = 0;
        }
        else
        {
            temp = temp + "</apply>\n";
            visit--;
        }
    }
};


#endif //__PRINTML_HPP__
