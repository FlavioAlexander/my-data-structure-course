// ListNode.h
// ListNode class definition.
#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List required to announce that class 		
// List exists so it can be used in the friend declaration
class List;                            

class ListNode 
{
	friend class List; // make List a friend

public:
	ListNode( int ); // constructor
	int getData() const; // return data in node

private:
	int data; // data
	ListNode *nextPtr; // next node in list
}; // end class ListNode
#endif
