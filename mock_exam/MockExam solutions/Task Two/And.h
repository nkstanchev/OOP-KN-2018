#pragma once
#include "LogicalExpression.h"
#include <iostream>
#include <vector>
class And : public LogicalExpression
{
    std::vector<LogicalExpression*> expressions;
public:
    void addExpression(LogicalExpression*);
    bool value();
    void print();
};