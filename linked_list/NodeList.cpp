#include "NodeList.h"
#include <iostream>
using namespace std;

// constructor
ListNode::ListNode( int info )
	: data( info ), nextPtr( 0 ) 
{ 
	// empty body
} // end ListNode constructor

// return copy of data in node
int ListNode::getData() const 
{ 
	return data; 
} // end function getData

