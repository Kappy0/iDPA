//Kappy; Hello World Adv program
//HelloWorld.cpp : An advanced version of the Hello World program

#include <iostream>

using namespace std;

void main()
{
	char string[15];

	cout << "Enter 'Hello World!' here: ";
	cin.getline(string, 14);
	cout << endl;
	cout << string;
	cout << endl << endl;

	system("PAUSE");
}