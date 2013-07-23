//Kappy; Class program
//Class.cpp : Definitions go here

#include <iostream>
#include <string>

#include "Class.h";

//In the .cpp, we declare all of our constructors, methods, and the desctructor.
Dog::Dog()
{
	name = "Default Dog";
	age = 1;
	energyLevel = 20;
	std::cout << "A default dog has been created.\n";
}

Dog::Dog(std::string newName, int newAge, int newEnergyLevel)
{
	name = newName;
	age = newAge;
	energyLevel = newEnergyLevel;
	std::cout << "A new dog, " << name << ", has been created!\n";
}

void Dog::Bark()
{
	std::cout << name << " is barking!\n";
}

void Dog::Eat()
{
	std::cout << name << " is eating.\n";
	energyLevel += 1;
}

Dog::~Dog()
{
	age = 0;
	energyLevel = 0;
	std::cout << name << " has died.\n";
}