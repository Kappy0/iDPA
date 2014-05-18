//Kappy; Class Exercise Program
//Robot.h : Declarations for the robot class

#include <iostream>
#include <string>

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
};
