//Kappy; Class Exercise Program
//Robot.cpp : Definitions for the robot class

#include "Robot.h"

Robot::Robot()
{
	name = "DEFAULT";
	health = 100;
	power = 10;
	std::cout << name << " has entered the battlefield!\n";
}

Robot::Robot(std::string newName, int newHealth, int newPower)
{
	name = newName;
	health = newHealth;
	power = newPower;
	std::cout << name << " has entered the battlefield!\n";
}

Robot::~Robot()
{
	health = 0;
	power = 0;
	std::cout << name << " has been destroyed.\n";
}

void Robot::Print()
{
	std::cout << "Name: " << name << "\n";
	std::cout << "Health: " << health << "\n";
	std::cout << "Power: " << power << "\n";
}

void Robot::Attack(Robot &defPlayer)
{
	int defValue = rand() % 11;

	if(defValue >= 0 && defValue < 6)
	{
		defPlayer.health -= power;
		std::cout << defPlayer.name << " has taken damage!\n";
	}
	else if(defValue > 5 && defValue <= 10)
	{
		defPlayer.Block(defPlayer);
		std::cout << defPlayer.name << " has blocked!\n";
	}
}

void Robot::Block(Robot &defPlayer)
{
	defPlayer.health = defPlayer.health -  (power / 2);
}