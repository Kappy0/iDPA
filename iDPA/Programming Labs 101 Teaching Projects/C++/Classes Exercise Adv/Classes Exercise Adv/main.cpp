//Kappy; Class Exercise Program Advanced
//main.cpp : Main function

#include "Robot.h"

void main()
{
	int atkValue;
	srand(time(NULL));

	Robot p1("Player 1", 100, 20);
	Robot p2("Player 2", 70, 35);

	std::cout << std::endl << std::endl;

	p1.Print();
	std::cout << std::endl;

	p2.Print();
	std::cout << std::endl;

	while(p1.health > 0 && p2.health > 0)
	{
		atkValue = rand() % 21;

		if(atkValue >= 0 && atkValue < 11)
		{
			p1.Attack(p2);
		}
		else if(atkValue > 10 && atkValue <= 20)
		{
			p2.Attack(p1);
		}
	}

	if(p1.health <= 0)
	{
		std::cout << p2.name << " is the winner!\n";
	}
	else if(p2.health <= 0)
	{
		std::cout << p1.name << " is the winner!\n";
	}

	std::cout << std::endl;

	p1.~Robot();
	p2.~Robot();

	std::cout << std::endl;

	system("PAUSE");
}