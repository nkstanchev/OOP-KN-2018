#include <iostream>
#include "LogicalExpression.h"
#include "Constant.h"
#include "And.h"
#include "Or.h"
#include "Pair.h"
#include "Relation.h"
int main()
{
    LogicalExpression * expr1 = new Constant(true);
    LogicalExpression * expr2 = new Constant(false);
    LogicalExpression * or1 = new Or(expr1, expr2);
    LogicalExpression * expr3 = new Constant(true);
    LogicalExpression * expr4 = new Constant(true);
    LogicalExpression * expr5 = new Constant(false);
    And * and1 = new And();
    and1->addExpression(expr3);
    and1->addExpression(expr4);
    and1->addExpression(expr5);

    LogicalExpression * expr6 = new Constant(true);
    And * and2 = new And();
    and2->addExpression(or1);
    and2->addExpression(and1);
    and2->addExpression(expr6);
    and2->print();

    Pair<char, int> pair('b', 2);
    


    return 0;
}