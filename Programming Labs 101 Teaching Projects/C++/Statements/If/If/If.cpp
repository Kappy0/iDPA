//Kappy; If Statement program
//If.cpp : Shows the uses of the 'if' statement and all its variations

#include <iostream>

using namespace std;

void main()
{
	bool statement, nest;
	double x, y, z;
	x = 10;
	y = 100;

	cout << "Is statement true or false? ";
	cin >> statement;
	
	cout << endl;

	cout << "Is nest true or false? ";
	cin >> nest;

	cout << endl << endl;

	//If statement
	if(statement == true)
	{
		cout << x / y;
	}
	else
	{
		cout << y / x;
	}

	cout << endl << endl;

	//Nested if statement
	if(nest == true)
	{
		cout << "Enter z: ";
		cin >> z;
		
		cout << endl << endl;

		//If-Else Statement
		if(z >= 0 && z <= 10)
		{
			if(z > 5)
			{
				cout << "z is greater than 5.";
			}
			else
			{
				cout << "z is less than 5.";
			}

			cout << endl << endl;
		}
		else if(z > 10 && z <= 20)
		{
			cout << "z is greater than 10.";

			cout << endl << endl;
		}
		else
		{
			cout << "ERROR: z is below zero or greater than 20.";

			cout << endl << endl;
		}
	}
	else
	{
		cout << "ERROR: nest is false.";
		
		cout << endl << endl;
	}

	system("PAUSE");
}