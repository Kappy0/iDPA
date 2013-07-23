// Ryan Klaproth
//
// Homework 2
// 
// Due 4/12/12
// 
// Linked Lists

#include "sllist.h"
#include <iostream>
#include <string>

void main()
{
	cout << "Homework 2" << endl;
	cout << "Ryan Klaproth" << endl << endl;

	SLList<int> list1;
	SLList<string> list2;
	SLList<string> list3;
	SLList<int> *list4;

	list1.add(5);
	list1.add(5);
	list1.add(10);
	list1.add(1);

	cout << "Printing List 1: " << endl;
	list1.print();

	if(list1.find(10))
	{
		cout << "There is a 10 in this list."<< endl;
	}
	else
	{
		cout << "There is not a 10 in this list."<< endl;
	}

	cout << "The size is: " << list1.size() << endl << endl;

	cout << "Removing 10 from List 1." << endl << endl;
	list1.remove(10);

	cout << "Printing List 1: " << endl;
	list1.print();

	if(list1.find(10))
	{
		cout << "There is a 10 in this list." << endl;
	}
	else
	{
		cout << "There is not a 10 in this list." << endl;
	}

	cout << "The size is: " << list1.size() << endl << endl;

	list2.add("a");
	list2.add("b");
	list2.add("c");
	list2.add("ab");
	list2.add("ac");
	list2.add("abc");
	list2.add("abra");

	cout << "Printing List 2: " << endl;
	list2.print();
	cout << "The size is: " << list2.size() << endl;

	if(list2.find("abra"))
	{
		cout << "A wild Abra has appeared!" << endl;
	}
	else
	{
		cout << "Abra used teleport and fled!" << endl;
	}

	cout << endl << endl;
	cout << "Removing abra from List 2." << endl << endl;
	list2.remove("abra");
	cout << endl;

	cout << "Printing List 2: " << endl;
	list2.print();
	cout << "The size is: "<<list2.size() << endl;

	if(list2.find("abra"))
	{
		cout << "A wild Abra has appeared!" << endl;
	}
	else
	{
		cout << "Abra used teleport and fled!" << endl;
	}
   
	cout << endl;

	list3 = list2;

	cout << "Printing List 2: " << endl;
	list2.print();
	cout << endl;

	cout << "Printing List 3: " << endl;
	list3.print();
	cout << endl;

	list2.add("alakazam");
	list3.add("kadabra");
	list3.remove("abc");

	cout << "Printing List 2: " << endl;
	list2.print();
	cout << endl;

	cout << "Printing List 3: " << endl;
	list3.print();
	cout << endl;

	list4 = new SLList<int>(list1);

	delete list4;

	cout << "List 4 deleted." << endl << endl;

	system("PAUSE");
}