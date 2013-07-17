// Program that illustrates the use of stacks.
// Programmed By: Monisha Pulimood for use in CSC 260 
//                

// Stack.cpp -	This class defines a stack 
//		implemented with a fixed-size array to hold the items.

#include <iostream>
#include <sstream>
#include "Stack.h"

using namespace std;

// Default constructor

Stack::Stack() 
{
	topOfStack = -1;
}

//	The data in the array parameter are copied into the attribute array.

Stack::Stack(int init [], int n) 
{
	if (n < MaxSize)
	{
		for (int i=0; i < n; i++)
			data[i] = init[i];
		topOfStack = n-1;
	}
	else
		topOfStack = -1;
}


void Stack::push (int item) 
{
	if (!isFull()) 
	{
        topOfStack++;
        data[topOfStack] = item;
    }
    else
        cout << "Stack is full." << endl;
}



void Stack::pop(void) 
{
	if (!isEmpty()) 
	{
        topOfStack--;
    }
}


int Stack::peek(void) 
{
	int temp;
	if (isEmpty()) 
	{
		cerr << "Stack Underflow" << endl;
		exit(1);
	}
	temp = data[topOfStack];
	return(temp);
}



bool Stack::isEmpty(void) 
{
	return (topOfStack == -1);
}

bool Stack::isFull (void) 
{
	return (topOfStack == MaxSize-1);
}


void Stack::clear(void)   
{
	topOfStack = -1;
}



// Print the data in the stack
ostream & operator<< (ostream & os, Stack& rhs) 
{
    int i;
    if (rhs.isEmpty())
        os << "empty." << endl;
    else
    {
        for (i = 0; i < rhs.topOfStack; i++)
            os << rhs.data [i] << ", ";
        os << rhs.data [i] << endl;
	}
    return os;
}
