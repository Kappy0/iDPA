//Kappy; Arrays program
//Arrays.cpp : Shows how arrays are used.

#include <iostream>
#include <string>

using namespace std;

void main()
{
	int cats[3], dogs[2];
	char name[] = { 'B', 'o', 'b' };

	cout << "How old are your 3 cats?" << endl;

	for(int i = 0; i < 3; i++)
	{
		cin >> cats[i];
		cout << endl;
	}

	dogs[0] = 200;
	dogs[1] = 2;

	for(int i = 0; i < 2; i++)
	{
		cout << dogs[i] << endl;
	}

	cout << "The ages of your cats are: ";

	for(int i = 0; i < 3; i++)
	{
		cout << cats[i] << " ";
	}

	cout << endl << endl;

	cout << "Hello " << name[0] << name[1] << name[2] << "!" << endl;

	system("PAUSE");
}