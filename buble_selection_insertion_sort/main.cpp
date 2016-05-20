/*/////////////////////////////////////////////////////////////////////
//																	 //
//			     Data Structure Assignment 6					     //
//																	 //
//	Programmer: Flavio Zhingri										 //
//	Instructor: Dr. Val Kolesnivok									 //
//	Date: 10/29/2013												 //
//																	 //
//	Description of the program:										 //
//																	 //
//	Create an array of 10000 random elements. Make two additional	 //
//	copies of the array. Use the original bubble sort, selection	 //
//	sort and insertion sort to sort a copy of the array. For each	 //
//	sort, have a function that implements that sort. In that		 //
//	function, count the number of times the operation that contri_	 //
//	butes the most to the runtime growth executes. Each sort should	 //
//	return a that number.											 //
//	Repat this process at least 100 times. For each sort, output	 //
//	the largest number that the operation that contributes the most	 //
//	to the runtime growth executes.									 //
//																	 //
//	Time spent: 6 hours												 //
//																	 //
//	Which algorithm is more efficient based on this empirical mea_	 //
//	surement? Which algorithm is less efficient based on this empi_	 //
//	rical measurements?												 //
//																	 //
// Selection sort is the most efficient, and bubble sort is the less //
//	efficient.														 //
//																	 //
/////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include"functions.h"
using namespace std;

int main()
{
	int const size = 10000; // size of the array
	int array1[size]; //array declaration
	int arraycopy1[size]; //array declaration
	int arraycopy2[size]; //array declaration
	int temp = 0; //temporary variable
	int temp1 = 0; //temporary variable
	int temp2 = 0; //temporary variable

	//Initializes random numbers
	srand (time(0));
	for (int counter = 0; counter <=10; counter++)
	{
		for (int i = 0; i<size; i++)
		{
			array1[i] = rand() % 100000 + 1;//range is from 0 to 100000
		}

		//copy array, first time
		for (int j = 0; j < size; j++)
		{
			arraycopy1[j] = array1[j];
		}

		//Copy array for second time
		for (int k = 0; k < size; k++)
		{
			arraycopy2[k] = array1[k];
		}

		//Buble Sort
		int counta = 0;
		bubbleSort(array1,size,counta); //call function
		if (counta > temp)
		{
			temp = counta; //keeping track of the biggest counter
		}

		//selection sort
		int countb = 0;
		selectionSort(arraycopy1,size,countb); // call function
		if (countb > temp1)
		{
			temp1 = countb; //keeping track of the biggest counter
		}

		//Insert sort
		int countc = 0;
		insertionSort(arraycopy2,size,countc); //call function
		if (countc > temp2)
		{
			temp2 = counta;  //keeping track of the biggest counter
		}
	}

	//Output counter values
	cout << "Number of operations for bubble sort is" << endl;
	cout << temp <<endl;
	cout << "Number of operations for selection sort is" << endl;
	cout << temp1 <<endl;
	cout << "Number of operations for insertion sort is" << endl;
	cout << temp2 <<endl;

	return 0;
}