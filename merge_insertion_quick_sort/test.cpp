/*/////////////////////////////////////////////////////////////////////
//																	 //
//			    	Programming Assignment 7						 //
//																	 //
//	Programmer: Flavio Zhingri										 //
//	Instructor: Dr. Val Kolesnikov									 //
//	Date: 11/05/13													 //
//																     //
//	Description of the program:										 //
//																	 //
//	Create an array of a 10,000 random integers. Make two additional //
//	copies of the array. Use the most efficient sort algorithm from  //
//	programming assignment 6, merge and quick sort algoriths to sort //
//	a copy of the array. For each sort, have a function that imple_  //
//	ments that sort (merge sort will likely require helper funct_	 //
//	ions ). In that function, count the number of times the operati_ //
//	on contributes the most to the runtime growth executes. Each	 //
//	sort function should return the number							 //
//																	 //
//	merge is the best one                                            //
/////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "functions.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	const int SIZE = 10000;	//Size of array
	int array1[SIZE];	//Array declaration
	int array_copy1[SIZE];	//Array declaration
	int array_copy2[SIZE];	//Array declaration
	int temp1 = 0;	//temporary variable
	int temp2 = 0;	//temporary variable
	int temp3 = 0;	//temporary variable
	int counter1, counter2, counter3; //counters declaration

	//Initializes random numbers
	srand (time(0));
	for (int counter = 0; counter <= 100; counter++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			array1[i] = rand() % 100000 + 1;//range is from 0 to 100000
		}

		// copy number one
		for (int k = 0; k < SIZE; k++)
		{
			array_copy1[k] = array1[k];
		}

		//copy number two of the array
		for (int l = 0; l < SIZE; l++)
		{
			array_copy2[l] = array1[l];
		}

		//insertion sort
		counter1 = 0;
		insertionSort(array1, SIZE, counter1); //call function
		if (counter1 > temp1)
		{
			temp1 = counter1;  //keeping track of the biggest counter
		}

		//Quick sort 
		int counter2 = 0;
		quickSort(array_copy1, 0, SIZE-1, counter2);
		if (counter2 > temp2 )
		{
			temp2 = counter2;
		}

		//merge sort
		counter3 = 0;
		sort(array_copy2, SIZE, counter3);
		if (counter3 > temp3 )
		{
			temp3 = counter3;
		}

	}

	//Output counter of three sort algorithms
	cout << endl << endl;
	cout << "The number of operations for insertion sort is" << endl;
	cout << temp1 << endl;

	cout << endl << endl;
	cout << "The number of operations for quick sort is" << endl;
	cout << temp2 << endl;

	cout << endl << endl;
	cout << "The number of operations for merge sort is" << endl;
	cout << temp3 << endl;

	return 0;
}
