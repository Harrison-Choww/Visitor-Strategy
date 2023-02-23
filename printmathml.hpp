#ifndef __PRINTMATHML_HPP__
#define __PRINTMATHML_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include <iostream>
#include <typeinfo>

class printMathML : public Visitor
{
public:
    ~printMathML() {}
    string temp = "";
    string extraspace = "  ";
    string tempspace = "";
    int visit = 1;
    bool embed = false;

    void visit_op(Op* Op1)
    {
        std::cout << "Op visited." << std::endl;
        cout << "<cn>" + Op1->stringify() + "</cn>\n" ;
    }

    void visit_rand(Rand* Random)
    {
        std::cout << "Rand visited." << std::endl;
        cout << "<cn>" + Random->stringify() + "</cn>\n";
    }

    void visit_add_begin(Add* node)
    {
        std::cout << "Add begin visited." << std::endl;
        //temp = "<math>\n  <apply>\n    <plus/>" + node->get_child(0)->stringify();
        cout << "visit: " << visit;
        cout << "child: " << node->get_child(0)->stringify() << endl;
        cout << "child->child: " << node->get_child(0)->get_child(0)->stringify() << endl;
        cout << "type: " << typeid((node)->get_child(0)->get_child(0)).name() << endl;

        if (visit % 3)
        {
            temp = "<math>\n  <apply>\n    <plus>\n    <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        else
        {
            temp = temp + "    <apply>\n      <plus>\n      <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        if (node->get_child(0)->stringify() != node->get_child(0)->get_child(0)->stringify())
        {
            embed = true;
            visit--;
        }
        visit++;
    }

    void visit_add_middle(Add* node)
    {
        std::cout << "Add middle visited." << std::endl;
        cout << "visit: " << visit;
        cout << "type id: " << typeid(node).name() << endl;

        /*if (embed)
        {
            temp = temp + "      <apply>\n        <plus>\n        <cn>" + node->get_child(0)->stringify() + "</cn>\n";
            embed = false;
        }
        else
        {
            temp = temp;
        }*/
        visit++;
    }

    void visit_add_end(Add* node)
    {
        std::cout << "Add end visited." << std::endl;
        /*temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n</math>";
        cout << temp << endl;*/
        cout << "visit: " << visit;

        if (visit == 3 && !embed)
        {
            temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            cout << temp << endl;
        }
        else if ((visit % 3) == 0)
        {
            //temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            temp = temp + "</math>";
            cout << temp << endl;
        }
        else
        {
            temp = temp + "      <cn>" + node->get_child(1)->stringify() + "</cn>\n    </apply>\n  </apply>\n";
        }
        visit++;
        //cout << temp << endl;
    }

    void visit_sub_begin(Sub* node)
    {
        std::cout << "Sub begin visited." << std::endl;

        if (visit % 3)
        {
            temp = "<math>\n  <apply>\n    <minus>\n    <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        else
        {
            temp = temp + "    <apply>\n      <minus>\n      <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        visit++;
    }

    void visit_sub_middle(Sub* node)
    {
        std::cout << "Sub middle visited." << std::endl;
        temp = temp;
        visit++;
    }

    void visit_sub_end(Sub* node)
    {
        std::cout << "Sub end visited." << std::endl;

        if (visit == 3)
        {
            temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            cout << temp << endl;
        }
        else if ((visit % 3) == 0)
        {
            //temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            temp = temp + "</math>";
            cout << temp << endl;
        }
        else
        {
            temp = temp + "      <cn>" + node->get_child(1)->stringify() + "</cn>\n    </apply>\n  </apply>\n";
        }
        visit++;
    }

    void visit_mult_begin(Mult* node)
    {
        std::cout << "Mult begin visited." << std::endl;

        if ((visit % 3) == 0 || visit == 1)
        {
            temp = "<math>\n  <apply>\n    <times>\n    <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        else
        {
            temp = temp + "    <apply>\n      <times>\n      <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        visit++;
    }

    void visit_mult_middle(Mult* node)
    {
        std::cout << "Mult middle visited." << std::endl;

        temp = temp;
        visit++;
    }

    void visit_mult_end(Mult* node)
    {
        std::cout << "Mult end visited." << std::endl;
        temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
        cout << temp << endl;
    }

    void visit_div_begin(Div* node)
    {
        std::cout << "Div begin visited." << std::endl;

        if ((visit == 1) && (node->get_child(0)->stringify() != node->get_child(0)->get_child(0)->stringify()))
        {
            temp = "<math>/n  <apply>\n    <divide>\n";
        }
        else if ((visit % 3) == 0)
        {
            temp = "<math>\n  <apply>\n    <divide>\n    <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        else
        {
            temp = temp + "    <apply>\n      <divide>\n      <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        visit++;
    }

    void visit_div_middle(Div* node)
    {
        std::cout << "Div middle visited." << std::endl;
        temp = temp;
        visit++;
    }

    void visit_div_end(Div* node)
    {
        std::cout << "Div end visited." << std::endl;

        if (visit == 3)
        {
            temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            cout << temp << endl;
        }
        else if ((visit % 3) == 0)
        {
            //temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            temp = temp + "</math>";
            cout << temp << endl;
        }
        else
        {
            temp = temp + "      <cn>" + node->get_child(1)->stringify() + "</cn>\n    </apply>\n  </apply>\n";
        }
        visit++;
    }

    void visit_pow_begin(Pow* node)
    {
        std::cout << "Pow begin visited." << std::endl;

        if ((visit % 3) ==0 || (visit ==1 ))
        {
            temp = "<math>\n  <apply>\n    <power>\n    <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        else
        {
            temp = temp + "    <apply>\n      <power>\n      <cn>" + node->get_child(0)->stringify() + "</cn>\n";
        }
        visit++;
    }

    void visit_pow_middle(Pow* node)
    {
        std::cout << "Pow middle visited." << std::endl;
        temp = temp;
        visit++;
    }

    void visit_pow_end(Pow* node)
    {
        std::cout << "Pow end visited." << std::endl;

        if (visit == 3)
        {
            temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            cout << temp << endl;
        }
        else if ((visit % 3) == 0)
        {
            //temp = temp + "    <cn>" + node->get_child(1)->stringify() + "</cn>\n  </apply>\n</math>";
            temp = temp + "</math>";
            cout << temp << endl;
        }
        else
        {
            temp = temp + "      <cn>" + node->get_child(1)->stringify() + "</cn>\n    </apply>\n  </apply>\n";
        }
        visit++;
    }
};


#endif //__PRINTMATHML_HPP__
