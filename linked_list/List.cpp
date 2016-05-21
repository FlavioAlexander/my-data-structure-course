#include "List.h"
#include <iostream>
using namespace std;

// default constructor
List::List() 
	: firstPtr( 0 ), lastPtr( 0 ) 
{

	// empty body
} // end List constructor

// destructor
List::~List()
{
	if ( !isEmpty() ) // List is not empty
	{    
		cout << "Destroying nodes ...\n";

		ListNode *currentPtr = firstPtr;
		ListNode *tempPtr;

		while ( currentPtr != 0 ) // delete remaining nodes
		{  
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		} // end while
	} // end if

	cout << "All nodes destroyed\n\n";
} // end List destructor

// insert node at front of list
void List::insertAtFront( int value )
{
	ListNode *newPtr = getNewNode( value ); // new node

	if ( isEmpty() ) // List is empty
		firstPtr = lastPtr = newPtr; // new list has only one node
	else // List is not empty
	{
		newPtr->nextPtr = firstPtr; // point new node to previous 1st node
		firstPtr = newPtr; // aim firstPtr at new node
	} // end else
} // end function insertAtFront

// insert node at back of list
void List::insertAtBack( int value )
{
	ListNode *newPtr = getNewNode( value ); // new node

	if ( isEmpty() ) // List is empty
		firstPtr = lastPtr = newPtr; // new list has only one node
	else // List is not empty
	{
		lastPtr->nextPtr = newPtr; // update previous last node
		lastPtr = newPtr; // new last node
	} // end else
} // end function insertAtBack

// delete node from front of list
bool List::removeFromFront( )
{
	if ( isEmpty() ) // List is empty
		return false; // delete unsuccessful
	else 
	{
		ListNode *tempPtr = firstPtr; // hold tempPtr to delete

		if ( firstPtr == lastPtr )
			firstPtr = lastPtr = 0; // no nodes remain after removal
		else
			firstPtr = firstPtr->nextPtr; // point to previous 2nd node

		delete tempPtr; // reclaim previous front node
		return true; // delete successful
	} // end else
} // end function removeFromFront

// delete node from back of list
bool List::removeFromBack( )
{
	if ( isEmpty() ) // List is empty
		return false; // delete unsuccessful
	else 
	{
		ListNode *tempPtr = lastPtr; // hold tempPtr to delete

		if ( firstPtr == lastPtr ) // List has one element
			firstPtr = lastPtr = 0; // no nodes remain after removal
		else 
		{
			ListNode *currentPtr = firstPtr;

			// locate second-to-last element            
			while ( currentPtr->nextPtr != lastPtr )    
				currentPtr = currentPtr->nextPtr; // move to next node

			lastPtr = currentPtr; // remove last node
			currentPtr->nextPtr = 0; // this is now the last node
		} // end else

		delete tempPtr; // reclaim former last node
		return true; // delete successful
	} // end else
} // end function removeFromBack

// is List empty?
bool List::isEmpty() const 
{ 
	return firstPtr == 0; 
} // end function isEmpty

// return pointer to newly allocated node
ListNode *List::getNewNode( int value )
{
	return new ListNode( value );
} // end function getNewNode

// display contents of List
void List::print() const
{
	if ( isEmpty() ) // List is empty
	{
		cout << "The list is empty\n\n";
		return;
	} // end if

	ListNode *currentPtr = firstPtr;

	cout << "The list is: ";

	while ( currentPtr != 0 ) // get element data
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	} // end while

	cout << "\n\n";
} // end function print

//Display the number of Nodes in the list
int List::numberOfNodes()
{
	if ( isEmpty ())  //Lis is empty
	{
		int number = 0;
		return number;  //return 0
	}
	else  //list is not empty
	{
		int counter = 0; //Initialize counter
		ListNode *currentPtr=firstPtr;  //Declare new pointer

		while ( currentPtr != NULL) //Loop
		{
			currentPtr=currentPtr->nextPtr;
			++counter; //counter to keep track of number of nodes
		}

		return counter; //return the value of the counter
	}
}

// Method to remove any node from the list
bool List:: removeFromList(int number1)
{
	if ( isEmpty()) //if list is empty
	{
		return false; //return false
	}
	else if (firstPtr->data == number1) // If we want to remove first node in the list
	{
		ListNode *temp = firstPtr; //create a temporary pointer

		firstPtr = firstPtr->nextPtr; //move to the next node
		delete temp; //delete temp
	}
	else if (lastPtr->data == number1) // If we want to remove first node in the list
	{
		ListNode *temp = lastPtr; //create a temporary pointer

		lastPtr = getPrevNodePtr(number1);
		lastPtr->nextPtr = 0;

		delete temp; //delete temp
	}
	else //if list isn't empty nor in the firstPtr
	{
		ListNode *temp = getNodePtr(number1); //temp gets the value of the node we enter

		if (temp == NULL) //if we enter a value that isnt in the linked list return unsuccessful
		{
			return false;
		}

		getPrevNodePtr(number1)->nextPtr = getNextNodePtr(number1); //traverse the list
		delete temp; //delete node
	}

	return true; //return true if node is deleted
}

// Insert a value after any node
bool List::insertAfter(int NodeValue,int newValue)
{
	if (isEmpty()) // if is empty
	{
		return false; //return unsuccessful
	}
	else
	{
		ListNode *temp1; //create a temporary pointer

		temp1 = getNodePtr(NodeValue); // set one equal to another

		if (temp1 == NULL) // If the number we enter isnt in the list, return unsuccessful
		{
			return false;
		}
		else if ( lastPtr->data == NodeValue) // if the number we enter is in the last node
		{
			ListNode *newNode = getNewNode(newValue);

			lastPtr ->nextPtr = newNode; // update previous last node
			lastPtr = newNode;	//new last node
		}
		else // If the number we enter is located anywhere, but not in the last node
		{
			ListNode *newNode = getNewNode(newValue); //create new node

			newNode->nextPtr = temp1->nextPtr;    //  newNoode points to a element in the list      
			temp1->nextPtr = newNode;// newNode is part of the linked list now
		}

		return true;
	}
}

//method to get a node in the linked list
ListNode *List::getNodePtr(int value)
{
	ListNode *currentPtr = firstPtr; //declared a temporary ptr which is equal to firstPtr

	while (currentPtr != NULL) //while loop to check if the value we are looking for is in the list
	{

		if (currentPtr->data == value) // check it its the value we are looking for
		{
			return currentPtr; //return address of the node we pointing to
		}

		currentPtr = currentPtr->nextPtr; //traversing the list
	}

	return NULL;  // if the value isnt in the linked list, return NULL
}

//method to get the next node in a linked list
ListNode *List::getNextNodePtr(int value)
{
	ListNode *currentPtr = firstPtr; //declared a temporary ptr which is equal to firstPtr

	while (currentPtr != NULL) //while loop to check if the value we looking for is in the list
	{

		if (currentPtr->data == value)
		{
			return currentPtr->nextPtr; //return addres of the next node we are pointing to
		}

		currentPtr = currentPtr->nextPtr; //traversing the list
	}

	return NULL; //if value isnt in the list
}

//method to get the prevous node in a linked list
ListNode *List::getPrevNodePtr(int value)
{
	ListNode *tempPtr = firstPtr; //Declaration of a extra Ptr

	while (tempPtr != NULL) //while loop to check if the value we looking for is in the list
	{
		if(firstPtr->data == value)
		{
			return NULL;
		}
		else
		{
			ListNode *temp2Ptr; //temporary node

			temp2Ptr = tempPtr; //keeping track of the node before the actual one
			tempPtr = tempPtr->nextPtr;	//traversing the list
			if (tempPtr->data == value) //checking if value is in the linked lis
			{
				return temp2Ptr; //retunr previous node
			}

		}
	}

	return NULL; //if value isnt in the linked list return NULL
}

