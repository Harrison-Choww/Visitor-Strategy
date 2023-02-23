#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "iterator.hpp"
#include "printLaTex.hpp"
#include "printmathml.hpp"
#include "printml.hpp"
#include "printlt.hpp"

int main() {
    Base* three = new Op(3);
    printLT* visitor1 = new printLT;
    printML* visitor2 = new printML;
    three->accept(visitor1, 0);
    Base* random = new Rand();
    random->accept(visitor1, 0);
    Base* seven = new Op(7);
    Base* add = new Add(three, seven);
    add->accept(visitor1, 0);
    add->accept(visitor1, 1);
    add->accept(visitor1, 2);
    Base* two = new Op(2);
    Base* add1 = new Add(add, two);
    add1->accept(visitor1, 0);
    add1->accept(visitor1, 1);
    add1->accept(visitor1, 2);
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* zero = new Op(0);
    Base* minus = new Sub(five, zero);
    minus->accept(visitor1, 0);
    minus->accept(visitor1, 1);
    minus->accept(visitor1, 2);
    Base* minus1 = new Add(one, minus);
    minus1->accept(visitor1, 0);
    minus1->accept(visitor1, 1);
    minus1->accept(visitor1, 2);
    Base* mult = new Mult(two, five);
    mult->accept(visitor1, 0);
    mult->accept(visitor1, 1);
    mult->accept(visitor1, 2);
    Base* pow = new Pow(five, two);
    pow ->accept(visitor1, 0);
    pow->accept(visitor1, 1);
    pow->accept(visitor1, 2);
    Base* div = new Div(five, two);
    div->accept(visitor1, 0);
    div->accept(visitor1, 1);
    div->accept(visitor1, 2);
    Base* div1 = new Div(mult, pow);
    div1->accept(visitor1, 0);
    div1->accept(visitor1, 1);
    div1->accept(visitor1, 2);
    Base* randomi = new Rand();
    Iterator it(three);
    cout << it.current_node()->stringify() << endl;
    cout << it.current_node()->evaluate() << endl;
    Iterator itr(randomi);
    cout << itr.current_node()->stringify() << endl;
    cout << itr.current_node()->evaluate() << endl;
    //Base* seven = new Op(7);
    Base* addi = new Add(three, seven);
    Base* adde = new Add(addi, two);
    Base* plusm = new Add(one, minus);
    Base* minusm = new Sub(minus, two);
    Iterator ita(plusm);
    Iterator itb(div);
    Iterator itc(pow);
    Iterator itd(mult);
    Iterator ite(div1);
    
    vector<Iterator> itv;

    itv.push_back(ita);
    itv.push_back(itb);
    itv.push_back(itc);
    itv.push_back(itd);
    itv.push_back(ite);

    for (std::vector<Iterator>::iterator itt = itv.begin(); itt != itv.end(); ++itt)
    {
        while (!itt->is_done())
        {
            itt->current_node()->accept(visitor1, itt->current_index());
            itt->current_node()->accept(visitor2, itt->current_index());
            itt->next();
        }
    }

    /*for (std::vector<Iterator>::iterator it2 = itv.begin(); it2 != itv.end(); ++it2)
    {
        while (!it2->is_done())
        {
            it2->current_node()->accept(visitor2, it2->current_index());
            it2->next();
        }
    }

    /*while (!ita.is_done())
    {
        //for (int i = 0; i <= ita.current_node()->number_of_children(); i++)
        //{            
        ita.current_node()->accept(visitor2, ita.current_index());
        //}
        ita.next();
    }*/

    /*while (!ita.is_done())
    {
        //for (int i = 0; i <= ita.current_node()->number_of_children(); i++)
        //{
        ita.current_node()->accept(visitor1, ita.current_index());
        //}
        ita.next();
    }*/
    //cout << ita.current_node()->stringify() << endl;
    //cout << ita.current_node()->evaluate() << endl;
    /*Base* minusi = new Sub(seven, three);
    Iterator itm(minusi);
    cout << itm.current_node()->stringify() << endl;
    cout << itm.current_node()->evaluate() << endl;
    Base* multi = new Mult(seven, three);
    Iterator itx(multi);
    cout << itx.current_node()->stringify() << endl;
    cout << itx.current_node()->evaluate() << endl;
    Base* divi = new Div(seven, three);
    Iterator itd(divi);
    cout << itd.current_node()->stringify() << endl;
    cout << itd.current_node()->evaluate() << endl;
    Base* powi = new Pow(seven, three);
    Iterator itp(powi);
    cout << itp.current_node()->stringify() << endl;
    cout << itp.current_node()->evaluate() << endl;
    /*Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;*/
    return 0;
}
