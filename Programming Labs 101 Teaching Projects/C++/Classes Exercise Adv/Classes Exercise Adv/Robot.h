//Kappy; Class Exercise Program
//Robot.h : Declarations for the robot class

//Because every .cpp will be using Robot.h, put all includes here
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Robot
{
	public:

		//Variables
		std::string name;
		int health, power;

		//Constructors and Destructor
		Robot();
		Robot(std::string name, int health, int power);
		~Robot();

		//Methods
		void Print();
		void Attack(Robot &defPlayer);
		void Block(Robot &defPlayer);
};
