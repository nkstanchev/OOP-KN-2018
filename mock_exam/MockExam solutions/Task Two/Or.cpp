#include "Or.h"

Or::Or(LogicalExpression* leftExpr, LogicalExpression* rightExpr)
{
    this->leftExpr = leftExpr;
    this->rightExpr = rightExpr;
}

bool Or::value()
{
    return this->leftExpr->value() || this->rightExpr->value();
}
void Or::print()
{
    std::cout << " or (" ; 
    leftExpr->print(); 
    std::cout << ","; 
    rightExpr->print(); 
    std::cout << ") ";
}