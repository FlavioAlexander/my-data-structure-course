/*/////////////////////////////////////////////////////////////////////
//																	 //								  	
//								Data Structure Assignment # 3		 //								  
//																	 //				                  
//	Developer: Flavio Zhingri										 //								  
//	Instructor: Dr. Val Kolesnikov									 //								  
//	Date: 10/10/2013												 //								  
//																	 //								  
//	Description of the program:										 //								  																									  
//	Add the following three utility methods to class lis			 //						  
//																	 //								  
//	ListNode *getNodePtr(int)										 //								  
//	ListNode *getNextNodePtr(int)									 //								  
//	ListNode *getPrevNodePtr(int)									 //							      
//																	 //								  
//	After you implement the three methods, redo the following two    //
//	methods to use the utility										 //
//	methods you have just created.									 //								  
//	bool insertAfter(int,int newValue)								 //								  
//	bool removeFromList(int)										 //								  
/////////////////////////////////////////////////////////////////////*/



// List class test program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "List.h" // List class definition

void instructions();
// display program instructions to user
void instructions()
{
	cout << "Enter one of the following:\n"
		<< "  1 to insert at beginning of list\n" 
		<< "  2 to insert at end of list\n" 
		<< "  3 to delete from beginning of list\n" 
		<< "  4 to delete from end of list\n" 
		<< "  5 to get the number of nodes\n"
		<< "  6 to remove a note from the list\n"
		<< "  7 to insert a number after a node\n"
		<< "  8 to end processing\n";
} // end function instructions

int main()
{
	// test List of int values
	List integerList;

	cout << "Testing a List of integers\n";
	instructions(); // display instructions

	int choice; // store user choice
	int value; // store input value

	do // perform user-selected actions
	{
		cout << "? ";
		cin >> choice;

		switch ( choice ) 
		{
		case 1: // insert at beginning
			cout << "Enter an integer: ";
			cin >> value;
			integerList.insertAtFront( value );
			integerList.print();
			break;
		case 2: // insert at end
			cout << "Enter an integer: ";
			cin >> value;
			integerList.insertAtBack( value );
			integerList.print();
			break;
		case 3: // remove from beginning
			if ( integerList.removeFromFront( ) )
				cout << "first element removed from list\n";
			integerList.print();
			break;
		case 4: // remove from end
			if ( integerList.removeFromBack( ) )
				cout << "last element removed from list\n";
			integerList.print();
			break;
		case 5: //NUmber of nodes
			cout << "The number of nodes are\t" << integerList.numberOfNodes()<<endl;
			break;
		case 6: //deletes a node
			int number;

			cout<< "Enter the number  you wish to delete" <<endl;
			cin>> number;
			integerList.removeFromList(number);
			integerList.print();
			//integerList.print();
			break;
		case 7: //insert a node after another one
			int node;
			int number1;

			cout << "Please enter after what number you want to add a new Node" <<endl;
			cin>>node;
			cout << "Please enter the new number" <<endl;
			cin >> number1;
			integerList.insertAfter(node,number1);
			integerList.print();
			break;
		
		} // end switch

	} while ( choice != 8); // end do...while

	cout << "End list test\n\n";

	return 0;
} // end main