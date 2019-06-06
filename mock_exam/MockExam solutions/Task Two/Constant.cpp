#include "Constant.h"

Constant::Constant(bool val)
{
    this->val = val;
}

bool Constant::value()
{
    return val;
}
void Constant::print()
{
    bool value = this->val;
    if(value)
    {
        std::cout << "true";
    }
    
    else
    {
        std::cout << "false";
    }
}
