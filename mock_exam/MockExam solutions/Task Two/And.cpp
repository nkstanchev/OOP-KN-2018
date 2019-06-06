#include "And.h"


void And::addExpression(LogicalExpression* expr)
{
    if(expressions.size() < 10)
    {
        this->expressions.push_back(expr);
    }
    else
    {
        std::cout << "Cannot add more expressions" << std::endl;
    }
    
}

bool And::value()
{
    size_t size = expressions.size();
    bool res = true;
    for(size_t i = 0; i < size; i++)
    {
        res  = res && expressions[i];
    }
    return res;
}
void And::print()
{
    size_t size = expressions.size();
    std::cout << " And (" ;
    for(size_t i = 0; i < size; i++)
    {
        expressions[i]->print();
        if(i != size -1)
        {
            std::cout << " , ";
        }
        
    }
    std::cout << ") ";
}