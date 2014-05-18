//Kappy; Switch Statement program
//Switch.cpp : Shows how switch statements are used.

#include <iostream>

using namespace std;

void main()
{
	int x;

	cout << "Enter a value between 1 and 5: ";
	cin >> x;

	cout << endl << endl;

	switch(x)
	{
	case 1:
		{
			cout << "One does not simply use a switch statement." << endl;
			break;
		}
	case 2:
		{
			cout << "Twice the fun." << endl;
			break;
		}
	case 3:
		{
			cout << "This would be three if-else statements." << endl;
			break;
		}
	case 4:
		{
			cout << "There are four options to choose from." << endl;
			break;
		}
	case 5:
		{
			cout << "Five more minutes..." << endl;
			break;
		}
	default:
		{
			cout << "ERROR: please enter a number between 1 and 5." << endl;
			break;
		}
	}

	system("PAUSE");
}