// TestDebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <bits/stdc++.h>
#include <iostream>
#include "TestDebug.h"

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{

			Print(i, j);

			sum = i * j;
		}
		cout << "\n\n\n";
	}
}



void Print(int i, int j)
{
	cout << setw(3) << i << setw(3) << "*" << setw(3) << j << setw(3) << "=" << setw(3) << i * j << "\n";
}
