//Kappy; Class program
//Class.h : Header file for Class.cpp. Declarations go here.

#include <string>
#include <iostream>

class Dog
{
	public:
		//Initialize Variables
		std::string name;
		int age, energyLevel;

		//Constructor and Destructor
		Dog();
		Dog(std::string newName, int newAge, int newEnergyLevel);
		~Dog();

		//Methods
		void Bark();
		void Eat();
};