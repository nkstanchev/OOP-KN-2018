#pragma once
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class Triangle
{
private:
	T* elements;
	int maxRows;
	int currentRow;
public:
	Triangle(int _maxRows,T elem)
	{
		this->maxRows = _maxRows;
		int maxElementsCount = 0;
		for (int i = 1; i <= this->maxRows; i++)
		{
			maxElementsCount = maxElementsCount + i;
		}
		this->elements = new T[maxElementsCount];
		this->elements[0] = elem;
		this->currentRow = 1;
	}
	void addRow(T* newRow)
	{
		int currentElementIndex = 0;
		for (int i = 1; i <= this->currentRow; i++)
		{
			currentElementIndex = currentElementIndex + i;
		}
		for (int j = 0; j < this->currentRow + 1; j++, currentElementIndex++)
		{
			this->elements[currentElementIndex] = newRow[j];
		}
		this->currentRow = this->currentRow + 1;
	}
	void print()
	{
		int count = 0;
		for (int i = 1; i <= currentRow; i++)
		{
			for (int j = 0; j < i; j++)
			{
				//cout << " * " << " ";
				cout << elements[count] << " ";
				count++;
			}
			cout << endl;
		}
	}
	T getAt(int i, int j)
	{
		assert(i < this->currentRow && j < this->currentRow);
		int currentElementIndex=0;
		for (int k = 1; k < i; k++)
		{
			currentElementIndex = currentElementIndex + k;
		}
		currentElementIndex = currentElementIndex + j;
		return this->elements[currentElementIndex];
	}
	bool isStable()
	{
		int currentElementIndex = 0;
		for (int i = 1; i <= this->currentRow; i++)
		{
			currentElementIndex = currentElementIndex + i;
		}
		currentElementIndex = currentElementIndex - 1;
		for (int j = currentElementIndex; j >= 0; j--)
		{
			for (int l = 0; l < j; l++)
			{
				cout << j << " " << l << endl;
				if (this->elements[j] < this->elements[l])
				{
					return false;
				}
			}
		}
		return true;
	}
	~Triangle()
	{
		delete[]this->elements;
	}
};

