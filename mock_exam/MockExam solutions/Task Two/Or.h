#pragma once
#include "LogicalExpression.h"
#include <iostream>
class Or : public LogicalExpression
{
    LogicalExpression* leftExpr;
    LogicalExpression* rightExpr;
public:
    Or(LogicalExpression*, LogicalExpression*);
    bool value();
    void print();
};