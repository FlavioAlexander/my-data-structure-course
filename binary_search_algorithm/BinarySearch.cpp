/*/////////////////////////////////////////////////////////////////////
//																	 //
//		         Data Structure Assignment 5						 //
//																	 //
//	Programmer: Flavio Zhingri										 //
//	Instructor: Dr. Val Kolesnikov									 //
//	Date: 10/18/2013												 //
//																	 //
//	Description of the program:										 //
//																	 //
//	Write a program that initializes an array of ten integers with	 //
//	the following numbers 21, 54, 126, 222, 239, 321, 456, 533, 737  //
//	,988. The program lets the player to guess one of the numbers.	 //
//	It should ask the user for a number, perform a binary search	 //
//	through the array and report whether or not it is one of the	 //
//	numbers in the array. The binary search should be implemented	 //
// as a function.													 //
//																	 //
//	Time spent: 3 hours												 //
//																	 //
/////////////////////////////////////////////////////////////////////*/


#include <iostream>
using namespace std;

int binarySearch(int array2[],int size,int value); //search function

int main()
{
	int const size = 10; //size of the array
	int value1;	//value to search
	int found;	//will call the function

	//Array initialization with given values
	int	array1[size] = {21,54,126,222,239,321,456,533,737,988};

	//Ask the user for the value to search
	cout << "Enter the number you want to search\n";
	cin >> value1;

	//call the binary search function
	found = binarySearch(array1,size,value1);

	//check if the value was found
	if (found !=-1 )
		cout << "\nValue found" << " in position " << ' ' << found << endl << endl;
	else
		cout<<"\nvalue not found\n" << endl;

	return 0;
}

//Binary search function definition
int binarySearch(int array2[],int size,int value)
{
	int first = 0;	//first index set to zero
	int last = size-1;	//last equal to last index in array
	int middle;	//variable to find middle position
	int position = -1;
	bool found = false; //bool variable to return tru or false depending on results;

	while ( !found  && first <= last)
	{
		middle = (first + last) / 2; //finding middle index

		if (array2[middle] == value) //if middle index is the value
		{
			found = true;	//return true
			position = middle;	//set position equal to middle index
		}
		else if (array2[middle] > value)	//in middle value greater than value
		{
			last = middle - 1; //new last index
		}
		else
		{
			first = middle + 1; //new first index
		}
	}

	return position; //return result
}

