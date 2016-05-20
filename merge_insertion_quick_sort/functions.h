#include <iostream>
using namespace std;

int partition(int set[], int start, int end, int &counter); //declaration of partitio function
void swap(int &value1, int &value2);	//declaration of swap function
void merge(int data[], int left, int middle1, int middle2, int right, int &counter );	//declaration of merge function

// Insertion sort
void insertionSort(int array3[], int size, int &counter1)
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
			counter1++;// counter number of operations

			//shift element one slot to the rigth
			array3[moveItem] = array3[moveItem - 1];
			moveItem--;
		} //end of whileloop

		array3[moveItem] = insert; //place inserted element into the array
	} //end for loop
}

//Qhick Sort
void quickSort(int set[], int start, int end, int &counter)
{
	int pivotPoint;

	if (start < end)
	{
		// Get the pivot point.
		pivotPoint = partition(set, start, end, counter);
		// Sort the first sub list.
		quickSort(set, start, pivotPoint - 1, counter);
		// Sort the second sub list.
		quickSort(set, pivotPoint + 1, end, counter);
	}
}

// partition function of quick sort 
int partition(int set[], int start, int end, int &counter)
{
	int pivotValue, pivotIndex, mid;	//Declaration of three variables

	mid = (start + end) / 2;	//finding the middle index
	swap(set[start], set[mid]);	//swap the middle index with the first one
	pivotIndex = start;	//set pivotIndex equal to star index
	pivotValue = set[start];	//get first value of array

	for (int scan = start + 1; scan <= end; scan++)	//foor loop
	{
		counter ++;  //counter th number of comparissons
		if (set[scan] < pivotValue)	
		{
			pivotIndex++;	//increment the index by one
			swap(set[pivotIndex], set[scan]);	//swap the values again
		}
	}

	swap(set[start], set[pivotIndex]);	//swap values again

	return pivotIndex;	//return the pivotindex
}

//swap function to use with quick sort
void swap(int &value1, int &value2)
{
	int temp = value1;	//temp will hold the value of value1

	value1 = value2;	//now value one will hold the value of value2
	value2 = temp;	//values is value one now
}

//merge function
void merge(int *data, int left, int middle1, int middle2, int right, int &counter )
{
	int leftIndex = left; // index into left subarray              
	int rightIndex = middle2; // index into right subarray         
	int combinedIndex = left; // index into temporary working array
	int combined[10000]; // working array               


	// merge arrays until reaching end of either            
	while ( leftIndex <= middle1 && rightIndex <= right )    
	{    
		// place smaller of two current elements into result  
		// and move to next space in vector                   
		if ( data[ leftIndex ] <= data[ rightIndex ] )        
			combined[ combinedIndex++ ] = data[ leftIndex++ ]; 
		else                                                  
			combined[ combinedIndex++ ] = data[ rightIndex++ ];

		counter++;	//count the number of comparissons
	} // end while                                           

	if ( leftIndex == middle2 ) // if at end of left array         
	{                                                               
		while ( rightIndex <= right ) // copy in rest of right array
			combined[ combinedIndex++ ] = data[ rightIndex++ ];       
	} // end if                                                     
	else // at end of right vector                                  
	{                                                               
		while ( leftIndex <= middle1 ) // copy in rest of left array
			combined[ combinedIndex++ ] = data[ leftIndex++ ];        
	} // end else                                                   

	// copy values back into original array
	for ( int i = left; i <= right; i++ )   
		data[ i ] = combined[ i ];           


} // end function merge

// sortsubvector function
void sortSubVector( int data[], int low, int high, int &counter )
{                                                 
	// test base case; size of array equals 1                        
	if ( ( high - low ) >= 1 ) // if not base case                   
	{                                                                
		int middle1 = ( low + high ) / 2; // calculate middle of array
		int middle2 = middle1 + 1; // calculate next element over      

		// split vector in half; sort each half (recursive calls)
		sortSubVector(data, low, middle1, counter ); // first half of array     
		sortSubVector(data, middle2, high, counter ); // second half of array    
		// merge two sorted arrays after split calls return
		merge(data, low, middle1, middle2, high, counter );               
	} // end if
} // end function sortSubVector

// sort fuction
void sort( int data[], int size, int &counter)
{
	sortSubVector(data,0, size-1, counter);	//calling sortsubvector function
}






