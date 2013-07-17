// Program that illustrates the use of class templates.
// Programmed By: Monisha Pulimood for use in CSC 260
//
// DO: Add maintenance information 
// stackDriver.cpp - driver to test definition of `stack'


#include <iostream>
#include <string>
#include "Stack.h"     


using namespace std;

int main (void)
{

    int element;
    
	Stack stackOne;
	
    // stack operations with the stack of integers
   
	for (int i=0; i<5; i++)
	{
		cout << "Enter an item to push onto the stack: ";
		cin >> element;
		stackOne.push(element);
	}

    cout << "The element at the top of stack is " << stackOne.peek() << endl;
    
    cout << "After pushing five elements, the stack is: " << stackOne << endl;
	
	
    // Use `pop()' to remove the top element of the stack
	
	stackOne.pop();

    cout << "After popping one element, the top of stack is now: " << stackOne.peek() << endl;


	for (int i=0; i<6; i++)
	{
		cout << "Enter an item to push onto the stack: ";
		cin >> element;
		stackOne.push(element);
	}

    cout << "After pushing six elements, the stack is now: " << stackOne << endl;
	

	stackOne.push(25);
    
    cout << "After pushing one more element, the stack is: " << stackOne << endl;
	
	while (!stackOne.isEmpty())
	{
		stackOne.pop();
	}
	
    cout << "After popping all elements, the stack is: " << stackOne << endl;

    //DO: After making Stack dynamic, test the following code
    /*
    
  	for (int i=0; i<20; i++)
	{
		cout << "Enter an item to push onto the stack: ";
		cin >> element;
		stackOne.push(element);
	}
  
    cout << "After pushing twenty elements, the stack is now: " << stackOne << endl;
	
    Stack stackTwo (stackOne);
    
    cout << "stackTwo is: " << stackTwo << endl;
    
   	for (int i=0; i<5; i++)
	{
		cout << "Enter an item to push onto the stack: ";
		cin >> element;
		stackTwo.push(element);
	}
   
    cout << "After pushing elements onto stackTwo it is now: " << stackTwo << endl;
    
    cout << "After pushing elements onto stackTwo, stackOne is now: " << stackOne << endl;
    
    
     while (!stackOne.isEmpty())
	{
		stackOne.pop();
	}
	
    cout << "After popping all elements from stackOne, it is: " << stackOne << endl;
   
    cout << "After popping all elements from stackOne, stackTwo is: " << stackTwo << endl;
    
    Stack stackThree;
    stackThree = stackTwo;
    
    cout << "After copying stackTwo to stackThree stackOne is: " << stackOne << endl;
    
    cout << "After copying stackTwo to stackThree stackTwo is: " << stackTwo << endl;
    
    cout << "After copying stackTwo to stackThree stackThree is: " << stackThree << endl;
    
     */
    return 0;
}

