// List.h
// List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;

#include "NodeList.h" // ListNode class definition

class List 
{
public:
	List(); // constructor
	~List(); // destructor
	void insertAtFront( int );
	void insertAtBack( int );
	bool removeFromFront( );
	bool removeFromBack( );
	bool isEmpty() const;
	void print() const;
	int numberOfNodes();
	bool insertAfter(int, int newValue);
	bool removeFromList(int);
	void reverse();      
private:
	ListNode *firstPtr; // pointer to first node
	ListNode *lastPtr; // pointer to last node

	// utility function to allocate new node
	ListNode *getNewNode( int );

	//utility function to get a Node fromlinked list
	ListNode *getNodePtr(int);

	//utility function to get next node in a linked list
	ListNode *getNextNodePtr(int);

	//utility function to get prev node in a linked list
	ListNode *getPrevNodePtr(int);
}; // end class List
#endif


