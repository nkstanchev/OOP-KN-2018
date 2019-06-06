#pragma once
template <typename U , typename V>
struct Pair
{
    U left;
    V right;
    Pair(U, V);
};
template <typename U , typename V>
Pair<U,V>::Pair(U left, V right)
{
    this->left = left;
    this->right = right;
}