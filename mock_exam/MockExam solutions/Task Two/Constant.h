#pragma once
#include "LogicalExpression.h"
#include <iostream>
class Constant : public LogicalExpression
{
    bool val;
public:
    Constant(bool);
    bool value();
    void print();
};