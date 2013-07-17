// Program that illustrates the use of stacks.
// Programmed By: Monisha Pulimood for use in CSC 260 
//                

// Stack.cpp -	This class defines a stack 
//		implemented with a fixed-size array to hold the items.

#include <iostream>
#include <sstream>
using namespace std;

const int MaxSize = 10;


#if !defined STACK_H
#define STACK_H

class Stack 
{
private:
	int data [MaxSize];
	int topOfStack;
public:
	Stack ();
	Stack (int [], int);
	void push (int); // adds an element to the top of the stack
	void pop (void); // removes an element from the top of the stack 
	                 // but does not return it
	int peek (void); // returns the element at the top of the stack 
	                 // but does not remove it
	
	bool isEmpty (void);
	bool isFull (void);
	void clear (void); // empties the stack
	
	friend ostream & operator<< (ostream &, Stack&);

};

#endif