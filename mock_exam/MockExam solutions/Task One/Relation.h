#pragma once
#include "Pair.h"
template <typename U , typename V>
class Relation
{
    Pair<U,V>* pairs;
    size_t pairsSize;
    size_t pairsCapacity;
    void copy(const Relation<U,V>&);
    void del();
    void resize();
public:
    Relation<U, V>();
    Relation<U, V>(U*, size_t,  V*, size_t);
    Relation<U, V>(const Relation<U,V>&);
    Relation<U, V>& operator =(const Relation<U,V>&);
    ~Relation<U, V>();
    bool operator[](const U&);
    Relation<U, V> operator *(Relation<U, V>&);
    Relation<U, V>& operator *=(Relation<U, V>&);
    bool isFunction();
    void addPair(Pair<U,V>&);
};
template <typename U , typename V>
void Relation<U, V>::copy(const Relation<U,V>& other)
{
    pairsSize = other.pairsSize;
    pairsCapacity = other.pairsCapacity;
    pairs = new Pair<U,V>[other.pairsCapacity];
    for(size_t i = 0; i < pairsSize; i++)
    {
        pairs[i] = other.pairs[i];
    }
}
template <typename U , typename V>
void Relation<U, V>::del()
{
    delete[] pairs;
}
template <typename U , typename V>
void Relation<U, V>::resize()
{
    pairsCapacity *= 2;
    Pair<U,V> newPairs = new Pair<U,V>[pairsCapacity];
    for(size_t i = 0; i < pairsSize; i++)
    {
        newPairs[i] = pairs[i];
    }
    delete[] pairs;
    this->pairs = newPairs;
}
template <typename U , typename V>
Relation<U, V>::Relation()
{
    pairsSize = 0;
    pairsCapacity = 4;
    pairs = new Pair<U,V>[pairsCapacity];
}
template <typename U , typename V>
Relation<U, V>::Relation(const Relation<U,V>& other)
{
    copy(other);
}
template <typename U , typename V>
Relation<U, V>& Relation<U, V>::operator=(const Relation<U,V>& other)
{
    if(this != & other)
    {
        copy(other);
        del();
    }
    return *this;
}
template <typename U , typename V>
Relation<U, V>::~Relation<U, V>()
{
    del();
}
template <typename U , typename V>
bool Relation<U, V>::operator[](const U& u)
{
    for(size_t i = 0; i < pairsSize; i++ )
    {
        if(u == pairs[i].left)
        {
            return true;
        }
    }
    return false;
}
template <typename U , typename V>
void Relation<U, V>::addPair(Pair<U,V>& pair)
{
    if(pairsSize + 1 > pairsCapacity)
    {
        resize();
    }
    pairs[pairsSize++];
}
template <typename U , typename V>
bool Relation<U, V>::isFunction()
{
   for(size_t i = 0; i < pairsSize; i++)
   {
       for(size_t j = 0; j < pairsSize; j++)
       {
           if(i != j)
           {
               if(pairs[i].left == pairs[j].left && pairs[i].right != pairs[j].right) return false;
           }
       }
   }
   return true;
}
template <typename U , typename V>
Relation<U, V> Relation<U, V>::operator *(Relation<U, V>& other)
{
    Relation<U, V> intersection;
    size_t size = 0;

    for(size_t i = 0; i < pairsSize; i++ )
    {
        for(size_t j = 0; j < other.pairsSize; j++)
        {
            if(pairs[i].left == other.pairs[j].left && pairs[i].right == other.pairs[j].right)
            {
                intersection->addPair(pairs[i]);
            }
        }
    }
    return intersection;
}
template <typename U , typename V>
Relation<U, V>& Relation<U, V>::operator *=(Relation<U, V>& other)
{
    return operator=(operator*(other));
}