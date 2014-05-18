// Ryan Klaproth
//
// Homework 1
// 
// Due 4/5/12
// 
// Programming puzzles

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

using namespace std;

//is_palindrome
bool is_palindrome(const char *s)
{
	if(s == NULL)
	{
		cout << "ERROR: a NULL pointer.";
		system("pause");
		exit(1);
	}

	bool isPal = true; //Create a flag for whether or not the string is a palindrome.
	int length = strlen(s);

	if(length) //If there is an actual string, keep going. Otherwise, return true.
	{
		for(int i = 0; i <= (length/2); i++) //Traverse the string exactly once, going from the start of the string to the middle.
		{
			if(isPal) //If isPal is true, keep going. Otherwise, stop and return false.
			{
				if(s[i] != (s[length - i - 1])) //If the start of the string is not the same as the end of the string, return false.
				{							   //Otherwise, continue.
					isPal = false;
				}
			}
			else
			{
				break;
			}
		}
	}
	return isPal;
}

//string_trim
void string_trim(char *s)
{
	if(s == NULL)
	{
		cout << "ERROR: a NULL pointer.";
		system("pause");
		exit(1);
	}

	if(s) //If there is a string, continue.
	{
		char *start = s;

		while(isspace(*start)) //While there are spaces, keep going until you hit a nonspace.
		{
			++start;
		}

		long length = strlen(start) + 1;

		memmove(s,start,length); // Remove all spaces from the left at the first nonspace.

		for(int i = (strlen(s) - 1); i >= 0; i--)
		{
			if(!isspace(s[i])) //If there isn't a space at any given i, keep going.
			{
				break;
			}
			else
			{
				s[i] = '\0'; //Set the end to after the last nonspace.
			}
		}
	}
}

//is_sorted
bool is_sorted(const int *ar, int size)
{
	if(ar == NULL)
	{
		cout << "ERROR: a NULL pointer.";
		system("pause");
		exit(1);
	}

	bool isSort = true; //Create a flag for whether or not the array is sorted.

	for(int i = 0; i < (size - 1); i++) //Runs through the array once.
	{
		if(isSort) //If the array is sorted, keep going. Otherwise, stop and return false.
		{
			if(ar[i] > ar[i+1]) //If the first number is greater than the next number, stop and return false.
			{					//Otherwise, keep going.
				isSort = false;
			}
		}
		else
		{
			break;
		}
	}
	return isSort;
}

//merge_sorted
void merge_sorted(const int *a1, int size1, const int *a2, int size2, int *a3, int size3)
{
	if((a1 || a2 || a3) == NULL)
	{
		cout << "ERROR: a NULL pointer.";
		system("pause");
		exit(1);
	}

	int i = 0;
	int j = 0;
	int k = 0;

	while((i < size1) && (j < size2) && (k < size3))  //This compares a1 and a2 while running through both of them, and
	{								   //places the lower of the two compared numbers into a3. This is done
		if(a1[i] < a2[j])			   //through incrementing the array whose number was just placed into a3, 
		{							   //comparing the next number to the one that wasn't picked. a3 is then
			a3[k++] = a1[i++];			   //incremented every time a number is placed into it.
		}
		else
		{
			a3[k++] = a2[j++];
		}
	}

	if(k == size3)
	{
		return;
	}
	else							
	{	
		if(i < size1)
		{
			while(i < size1 && k < size3)
			{
				a3[k++] = a1[i++];
			}
		}
		else
		{
			while(j < size2 && k < size3)
			{
				a3[k++] = a2[j++];
			}
		}
	}
}

//sort_elements
void sort_elements(int *ar, int num_elements)
{
	if(ar == NULL)
	{
		cout << "ERROR: a NULL pointer.";
		system("pause");
		exit(1);
	}

	int i = 0;
	int j = (num_elements - 1);
	int swap;

	while(i < j)
	{
		while((ar[i] == 0) && (i < j)) //Finds the next 0 from the left
		{
			i++;
		}

		while((ar[j] == 1) && (j > i)) //Finds the next 0 from the right
		{
			j--;
		}
		
		if(i < j) //Swaps 1's and 0's
		{
			swap = ar[i];
			ar[i] = ar[j];
			ar[j] = swap;
		}
	}
}

//most_frequent
int most_frequent(const int *ar, int num_elements)
{
	if(ar == NULL)
	{
		cout << "ERROR: a NULL pointer.";
		system("pause");
		exit(1);
	}

	int count = 0; //Counts the number of times a given character appears.
	int mostFreq; //Stores the current most frequent number.

	for(int i = 0; i < num_elements; i++)
	{
		int j = 1;
		while(ar[i] == ar[i+j])
		{
			j++;
		}

		if(j >= count) //If the count is higher than the previous highest count,
		{			   //then store as new most frequent number.
			count = j;
			mostFreq = ar[i];
		}
	}
	return mostFreq;
}

//findMaxDistance
struct Vect_t // A structure for a position in the 3-dimensional system
{ 
  float x; 
  float y; 
  float z;
};

void findMaxDistance(int nPlayers, const Vect_t playerArray[], float &maxDist, float &minDist)
{
     Vect_t tmpVect;   //Temporary vector
     float tmpDist; //Temporary distance

     for(int i = 0; i < (nPlayers - 1); i++)
     {
        for(int j = (i + 1); j < nPlayers; j++)
        {
           //Find a vector between point i and j
           tmpVect.x = playerArray[i].x - playerArray[j].x;
           tmpVect.y = playerArray[i].y - playerArray[j].y;
           tmpVect.z = playerArray[i].z - playerArray[j].z;
 
           //Get its length
           tmpDist = (tmpVect.x * tmpVect.x 
                    + tmpVect.y * tmpVect.y 
                    + tmpVect.z * tmpVect.z);

		   if(i == 0 && j == 1)
		   {
			   maxDist = minDist = tmpDist;
		   }
		   else
		   {
			   if(tmpDist > maxDist)
			   {
				   maxDist = tmpDist;
			   }
			   else if(tmpDist < minDist)
			   {
				   minDist = tmpDist;
			   }
		   }
        }
     }
	 maxDist = (float)sqrt(maxDist);
	 minDist = (float)sqrt(minDist);
}

int main()
{
	cout << "Homework 1";
	cout << endl << "Ryan Klaproth";
	cout << endl << endl;
	cout << endl << endl;

	//Test is_palindrome
	cout << "Testing is_palindrome:";
	cout << endl << endl;

	const char *palTest1 = "LOL";
	const char *palTest2 = "What";

	if(is_palindrome(palTest1))
	{
		cout << palTest1 << " is a palindrome.";
	}
	else
	{
		cout << palTest1 << " is not a palindrome.";
	}

	cout << endl;

	if(is_palindrome(palTest2))
	{
		cout << palTest2 << " is a palindrome.";
	}
	else
	{
		cout << palTest2 << " is not a palindrome.";
	}

	cout << endl << endl;
	cout << endl << endl;

	//Test string_trim
	cout << "Testing string_trim:";
	cout << endl << endl;

	char trimTest1[50] = "      Testing        ";
	char trimTest2[50] = "   Testing 2          ";

	cout << trimTest1 << " <- This is the string of the 1st test without the trim.";
	cout << endl;
	cout << "The length of this string is " << strlen(trimTest1);
	cout << endl << endl;
	cout << trimTest2 << " <- This is the string of the 2nd test without the trim.";
	cout << endl;
	cout << "The length of this string is " << strlen(trimTest2);

	string_trim(trimTest1);
	string_trim(trimTest2);
	cout << endl << endl;

	cout << trimTest1 << " <- This is the string of the 1st test with the trim.";
	cout << endl;
	cout << "The length of this string is " << strlen(trimTest1);
	cout << endl << endl;
	cout << trimTest2 << " <- This is the string of the 2nd test with the trim.";
	cout << endl;
	cout << "The length of this string is " << strlen(trimTest2);

	cout << endl << endl;
	cout << endl << endl;

	//Test is_sorted
	cout << "Testing is_sorted:";
	cout << endl << endl;

	const int size1 = 5;
	const int size2 = 13;
	int sortTest1[size1] = {1,2,3,4,5};
	int sortTest2[size2] = {1,3,5,7,9,11,13,2,4,6,8,10,12};

	cout << "Is {1,2,3,4,5} sorted in ascending order?";
	cout << endl;

	if(is_sorted(sortTest1,size1))
	{
		cout << "Yes.";
	}
	else
	{
		cout << "No.";
	}

	cout << endl << endl;

	cout << "Is {1,3,5,7,9,11,13,2,4,6,8,10,12} sorted in ascending order?";
	cout << endl;

	if(is_sorted(sortTest2,size2))
	{
		cout << "Yes.";
	}
	else
	{
		cout << "No.";
	}

	cout << endl << endl;
	cout << endl << endl;

	//Test merge_sorted
	cout << "Testing merge_sorted:";
	cout << endl << endl;

	cout << "Test 1.";
	cout << endl << endl;

	const int sA1 = 5;
	const int sB1 = 7;
	const int sC1 = 12;

	const int a1[sA1] = {1,2,3,4,5};
	const int b1[sB1] = {1,3,4,6,7,9,10};
	int c1[sC1];

	cout << "Merging the array {";
	for(int i = 0; i < sA1; i++)
	{
		cout << a1[i] << ",";
	}
	cout << "}";
	cout << endl;

	cout << "with the array {";
	for(int i = 0; i < sB1; i++)
	{
		cout << b1[i] << ",";
	}
	cout << "}";
	cout << endl;

	cout << "will result in the array {";

	merge_sorted(a1,sA1,b1,sB1,c1,sC1);

	for(int i = 0; i < sC1; i++)
	{
		cout << c1[i] << ",";
	}
	cout << "}";
	cout << endl << endl;

	cout << "Test 2.";
	cout << endl << endl;

	const int sA2 = 8;
	const int sB2 = 9;
	const int sC2 = 17;

	const int a2[sA2] = {2,4,6,8,10,12,14,16};
	const int b2[sB2] = {1,1,4,4,6,7,9,10,10};
	int c2[sC2];

	cout << "Merging the array {";
	for(int i = 0; i < sA2; i++)
	{
		cout << a2[i] << ",";
	}
	cout << "}";
	cout << endl;

	cout << "with the array {";
	for(int i = 0; i < sB2; i++)
	{
		cout << b2[i] << ",";
	}
	cout << "}";
	cout << endl;

	cout << "will result in the array {";

	merge_sorted(a2,sA2,b2,sB2,c2,sC2);

	for(int i = 0; i < sC2; i++)
	{
		cout << c2[i] << ",";
	}
	cout << "}";

	cout << endl << endl;
	cout << endl << endl;

	//Test sort_elements
	cout << "Testing sort_elements:";

	cout << endl << endl;

	const int eSize1 = 5;
	const int eSize2 = 12;
	int eSortTest1[eSize1] = {1,0,0,1,1};
	int eSortTest2[eSize2] = {1,0,1,0,1,0,0,1,0,0,1,0};

	cout << "The array {";
	for(int i = 0; i < eSize1; i++)
	{
		cout << eSortTest1[i] << ",";
	}
	cout << "}" << " sorted is";
	cout << endl;

	sort_elements(eSortTest1,eSize1);

	cout << "{";
	for(int i = 0; i < eSize1; i++)
	{
		cout << eSortTest1[i] << ",";
	}
	cout << "}";

	cout << endl << endl;

	cout << "The array {";
	for(int i = 0; i < eSize2; i++)
	{
		cout << eSortTest2[i] << ",";
	}
	cout << "}" << " sorted is";
	cout << endl;

	sort_elements(eSortTest2,eSize2);

	cout << "{";
	for(int i = 0; i < eSize2; i++)
	{
		cout << eSortTest2[i] << ",";
	}
	cout << "}";

	cout << endl << endl;
	cout << endl << endl;

	//Test most_frequent
	cout << "Testing most_frequent:";
	cout << endl << endl;

	const int fSize1 = 10;
	const int fSize2 = 15;
	const int mostTest1[fSize1] = {1,3,3,5,7,7,7,7,7,8};
	const int mostTest2[fSize2] = {1,2,3,4,4,4,4,5,6,7,8,8,8,8,8};

	cout << "The most frequent number in the array {";
	for(int i = 0; i < fSize1; i++)
	{
		cout << mostTest1[i] << ",";
	}
	cout << "} is ";
	cout << endl;
	cout << most_frequent(mostTest1,fSize1);
	cout << endl << endl;

	cout << "The most frequent number in the array {";
	for(int i = 0; i < fSize2; i++)
	{
		cout << mostTest2[i] << ",";
	}
	cout << "} is ";
	cout << endl;
	cout << most_frequent(mostTest2,fSize2);

	cout << endl << endl;
	cout << endl << endl;

	//Test findMaxDistance
	cout << "Testing findMaxDistance:";
	cout << endl << endl;

	float maxDist1 = 0.0f;
	float minDist1 = 0.0f;
	float maxDist2 = 0.0f;
	float minDist2 = 0.0f;

	const int dSize1 = 7;
	const int dSize2 = 5;
	const Vect_t dTest1[dSize1] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{1,3,5},{5,7,9},{11,13,15}};
	const Vect_t dTest2[dSize2] = {{2,4,6},{8,10,12},{1,2,4},{2,3,5},{3,4,6}};

	findMaxDistance(dSize1,dTest1,maxDist1,minDist1);

	cout << "Test1:";
	cout << endl << endl;

	cout << "Maximum Distance: " << maxDist1;
	cout << endl;
	cout << "Minimum Distance: " << minDist1;

	cout << endl << endl;

	cout << "Test2:";
	cout << endl << endl;

	findMaxDistance(dSize2,dTest2,maxDist2,minDist2);

	cout << "Maximum Distance: " << maxDist2;
	cout << endl;
	cout << "Minimum Distance: " << minDist2;

	cout << endl << endl;

	cout << endl << endl;
	cout << "End of tests.";
	cout << endl;
	system("pause");
	return(0);
}