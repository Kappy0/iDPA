//Kappy; Class program
//main.cpp : The main part of the program.

#include <iostream>
#include "Class.h";

void main()
{
	Dog ace;
	Dog lucky("Lucky", 3, 20);

	for(int i = 0; i < 10; i++)
	{
		if(lucky.energyLevel < 15)
		{
			lucky.Bark();
		}
		lucky.energyLevel--;
	}

	ace.~Dog();
	lucky.~Dog();

	system("PAUSE");
}