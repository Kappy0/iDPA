//Kappy; Input/Output program
//IO.cpp : Shows input and output application in c++

#include <iostream>
#include <string>

using namespace std;

void main()
{
	int x;
	string y;

	cout << "Input (cin) takes your input and assigns it to a variable" << endl << endl;

	cout << "Input x here: ";
	cin >> x;
	cout << endl;

	cout << "Input y here: ";
	cin >> y;
	cout << endl;

	cout << endl << endl;

	cout << "Output (cout) outputs your variables" << endl << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	system("PAUSE");
}