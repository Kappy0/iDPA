//Kappy; Class Exercise Program
//main.cpp : Main function

#include "Robot.h"

void main()
{
	Robot defaultRobot;
	Robot p1("Player 1", 100, 20);
	Robot p2("Player 2", 70, 35);

	std::cout << std::endl << std::endl;

	defaultRobot.Print();
	std::cout << std::endl;

	p1.Print();
	std::cout << std::endl;

	p2.Print();
	std::cout << std::endl;

	defaultRobot.~Robot();
	p1.~Robot();
	p2.~Robot();

	std::cout << std::endl;

	system("PAUSE");
}