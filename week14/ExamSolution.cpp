// ExamSolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Triangle.h"
#include "Header.h"
int main()
{
	/*
	int arr[2] = { 1,3 };
	int arr2[3] = { 4,5,6 };
	Triangle<int> A(3, 2);
	A.addRow(arr);
	A.addRow(arr2);
	A.print();
	cout << A.getAt(1, 1) << endl;
	A.isStable();
	*/
	Parrot p1("Beck");
	Monkey m1("Jeff");
	Zoo z1;
	z1.add(&p1);
	z1.add(&m1);
	z1.morningSounds();
    return 0;
}

