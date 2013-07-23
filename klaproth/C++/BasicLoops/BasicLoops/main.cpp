#include <iostream>

using namespace std;

void main()
{
	int k = 0;
	k++;        // same as k = k+1
	k--;        // same as k = k-1
	/*
	int something = 10;
	for(int i = 0; i < something; i++)
	{
		if(i == 5)
		{
			cout << i << endl;  //stuff
		}
	}
	cout << "done with for" << endl;
	*/

	/*
	int i = 0;
	while(i < 100000)
	{
		cout << i << endl; //stuff
		i++;
	}
	cout << "done with while" << endl;
	*/

	int i = 4;
	cout << i << endl;

	do
	{
		
		i++;
		cout << i << endl;
	}
	while(i == 5); 

	cout << "done with do-while" << endl;


	system("Pause");
}