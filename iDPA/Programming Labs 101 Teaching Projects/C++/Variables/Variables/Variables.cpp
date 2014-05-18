//Kappy; Variables program
//Variables.cpp : Showcases different types of variables and how they're used.

#include <iostream>
#include <string>

using namespace std;

void main()
{
	int x = 2;
	double y = 3.14;
	float z = 3.14f;
	char a = 99;
	char b = 'R';
	string c = "Hello ";
	string d = "World!";
	bool e;

	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "(int)a = " << (int)a << endl;
	cout << "a + b = " << a + b << endl;
	cout << "c + d = " << c + d << endl;

	cout << endl << endl;

	if(z == 3.14)
	{
		cout << "Yay!" << endl;
	}
	else if(y == 3.14)
	{
		cout << "What?" << endl;
	}

	system("PAUSE");

}