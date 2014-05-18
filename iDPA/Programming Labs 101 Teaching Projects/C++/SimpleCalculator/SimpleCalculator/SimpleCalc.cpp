//Kappy; Simple Calculator
//SimpleCalculator.cpp : A simple calculator program

#include <iostream>

using namespace std;

void main()
{
	double x, y, z;
	char again, operation;
	
	do
	{
		cout << "Enter x: ";
		cin >> x;
		cout << endl;

		cout << "Enter y: ";
		cin >> y;
		cout << endl;

		cout << "Enter A/S/M/D for the operation you want to perform: ";
		cin >> operation;

		switch(operation)
		{
			case 'A':
				{
					z = x + y;
					break;
				}
			case 'S':
				{
					z = x - y;
					break;
				}
			case 'M':
				{
					z = x * y;
					break;
				}
			case 'D':
				{
					z = x / y;
					break;
				}
		}

		cout << endl << endl;
		cout << "The result is " << z;
		cout << endl << endl;

		cout << "Perform another calculation? (Y/N): ";
		cin >> again;
		cout << endl;
	}
	while(again == 'Y');

	cout << "Goodbye!";
	cout << endl << endl;

	system("PAUSE");
}