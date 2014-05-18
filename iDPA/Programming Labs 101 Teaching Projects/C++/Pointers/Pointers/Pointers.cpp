//Kappy; Pointers prototype
//Pointers.cpp : Shows how pointers are used

#include <iostream>
using namespace std;

void triple (int *number)
{
     *number *= 3;
}

int main()
{
    int x = 5;
    int *ptr = &x;
    
    cout << "x is: " << x << endl;
	cout << "Address of x is: " << ptr << endl << endl;;
    triple(ptr);
    cout << "x is now: " << *ptr << endl;
	cout << "Address of x is: " << ptr << endl;
    
	system("PAUSE");
}