#include <iostream>
using namespace std;

//Bubble sort function
void bubbleSort(int array2[],int size,int &counter1)
{
	bool swap;
	int temp;

	do
	{
		swap = false; //initializes swap as false
		for (int count = 0; count < (size-1); count++)//count number of passes
		{
			counter1++; //count the number of operations

			if (array2[count] > array2[count +1]) //swap process
			{
				temp = array2[count]; 
				array2[count] = array2[count + 1];
				array2[count +1] = temp;
				swap = true; //if swap is done return true
			}
		}
	}while (swap);//end do-while loop
}

//Selection sort function
void selectionSort(int array2[],int size, int &counter2)
{
	int startScan, minIndex, minValue; //variables declaration

	for (startScan = 0; startScan < (size - 1); startScan++)//for loop, passes number
	{
		minIndex = startScan; //set min equal to zero
		minValue = array2[startScan]; //find min value in first position

		for (int index = startScan + 1; index < size; index++)
		{
			counter2++; //count the number of operations

			if (array2[index] < minValue) //swap process
			{
				minValue = array2[index];
				minIndex = index;
			}
		}

		array2[minIndex] = array2[startScan];// more swaping processs
		array2[startScan] = minValue;
	}
}

//Insertion sort  function
void insertionSort(int array3[],int size,int &counter3)
{
	int insert;

	//loop over the elements of the array
	for (int next = 1; next < size; next++)
	{
		insert = array3[next]; //store the value in the current element
		int moveItem = next; //initialize location to place element

		//search fpr the location in which to put the current element
		while (( moveItem > 0 ) && ( array3[moveItem - 1] > insert))
		{
			counter3++;// counter number of operations

			//shift element one slot to the rigth
			array3[moveItem] = array3[moveItem - 1];
			moveItem--;
		} //end of whileloop

		array3[moveItem] = insert; //place inserted element into the array
	} //end for loop
}




