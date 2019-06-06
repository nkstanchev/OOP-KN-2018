#pragma once
class LogicalExpression
{
    //bool val;
public:
    //LogicalExpression();
    //LogicalExpression(bool);
    //void setValue(bool val);
    //bool getValue();
    virtual bool value() = 0;
    virtual void print() = 0;
};