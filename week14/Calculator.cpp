// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class NumberTransformation
{
public:
	virtual int transform(int x) = 0;
};
class Id:public NumberTransformation
{
private:
	int n;
public:
	Id(int n)
	{
		this->n = n;
	}
	virtual int transform(int x)
	{
		return this->n;
	}
};
class Sum:public NumberTransformation
{
private:
	int n;
public:
	Sum(int n)
	{
		this->n = n;
	}
	virtual int transform(int x)
	{
		return (this->n + x);
	}
};
class Product :public NumberTransformation
{
private:
	int n;
public:
	Product(int n)
	{
		this->n = n;
	}
	virtual int transorm(int x)
	{
		return (this->n*x);
	}
};
class Calculator
{
private:
	vector<NumberTransformation*> list;
public:
	void add(NumberTransformation* addition)
	{
		list.push_back(addition);
	}
	int calculate(int n)
	{
		for (int i = 0; i < list.size(); i++)
		{
			list[i]->transform(n);
		}
		return n;
	}
};

int main()
{
    return 0;
}

