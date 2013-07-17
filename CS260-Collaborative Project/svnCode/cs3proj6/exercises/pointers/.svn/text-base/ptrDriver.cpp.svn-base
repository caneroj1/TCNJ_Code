// Program that illustrates the use of pointers.
// Programmed By: Monisha Pulimood for use in CSC 260, 
// DO: Add maintenance information 

#include <iostream>
#include "ptrFunctions.h"

using namespace std;

int main (void)
{
	
    int a, b;			// integer variables
    // DO: Declare pointer variables ptrA and ptrB that will refer to integer data
	
    int intArray[MaxSize]; // an array of integers
    int index;          // loop control variable - index of the array
    int count;          // number of elements in array
    
	// ##########################
	// Pointer variable manipulations
	
    a = 999;
    // DO: assign the memory address of a to ptrA, ie make ptrA
    // 'point to' a
	
	
    b = 65;
    // DO: assign the memory address of b to ptrB, ie make ptrB
    // 'point to' b
 
	
    cout << "\nPart 1 - Pointer variables" << endl;
    
	// DO: Complete the cout statement to reflect the display messages
    cout << "\nVariable a is stored at address  " << ?? << endl;
    cout << "Pointer ptrA is stored at address " << ?? << endl;
    cout << "Variable b is stored at address  " << ?? << endl;
    cout << "Pointer ptrB is stored at address " << ?? << endl;
    cout << "Use diagrams to illustrate the above in memory " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
	
	//DO: use 'ptrA' to display the value
    cout << "Pointer ptrA holds the value " << ?? << endl;			
    
	//DO: use 'ptrA' to display the value
	cout << "\nVariable a holds integer " << ?? << endl;	
    cout << "Use diagrams to illustrate the above in memory " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
	
	
	//DO: use 'ptrB' to display the value
    cout << "Pointer ptrB holds  the value " << ?? << endl;			
    
	//DO: use 'ptrB' to display the value
	cout << "\nVariable b holds integer " << ?? << endl;	
    cout << "Use diagrams to illustrate the above in memory " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
	
    // DO: Assign ptrA to ptrB;
	
    
	
    
    cout << "\nAfter 1st assignment operation  " << endl;
	
 	//DO: use 'ptrA' to display the value
    cout << "Pointer ptrA holds  " << ?? << endl;			
    
	//DO: use 'ptrA' to display the value
	cout << "\nVariable a holds integer " << ?? << endl;	
	
	//DO: use 'ptrB' to display the value
    cout << "Pointer ptrB holds  " << ?? << endl;			
    
	//DO: use 'ptrB' to display the value
	cout << "\nVariable b holds integer " << ?? << endl;	
    cout << "Use diagrams to illustrate the above in memory " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
	
	
    //DO: Use ptrA to change the value of 'a' to 43
    
    
    cout << "\nAfter 2nd assignment operation " << endl;
	
 	//DO: use 'ptrA' to display the value
    cout << "Pointer ptrA holds  " << ?? << endl;			
    
	//DO: use 'ptrA' to display the value
	cout << "\nVariable a holds integer " << ?? << endl;	
 	
	//DO: use 'ptrB' to display the value
    cout << "Pointer ptrB holds  " << ?? << endl;			
    
	//DO: use 'ptrB' to display the value
	cout << "\nVariable b holds integer " << ?? << endl;	

    cout << "Use diagrams to illustrate the above in memory " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
	
	
	
    //############################
    cout << "\nPart 2 - arrays as pointers" << endl;
	
    cout << "Enter the number of elements in the array (between 0 and " ;
	cout << MaxSize << "): " << endl;
    cin >> count;
    
    for (index = 0; index < count; ++index)
		intArray [index] = index;
    cout << "\nValues stored in the array initially" << endl;
    for (index = 0; index < count; ++index)
		cout << intArray [index] << " ";
    cout << endl;
	
	
    intArrayManip (intArray, count);
    
    cout << "Returned from function intArrayManip () - now the values are" << endl;
	
	// DO: Use pointer notation to display data in the array
    cout << "Displaying using pointer notation" << endl;
    
 
    cout << endl;
    for (index = 0; index < count; ++index)
		cout << *intArray + index << " ";
    cout << endl;
    cout << "Explain what these numbers represent " << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
    
	cout << endl;
    for (index = 0; index < count; ++index)
		cout << *(intArray + index) << " ";
    cout << endl;
    cout << "Explain what these numbers represent " << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
    
    cout << "Explain why there is a difference in the data that is displayed by the two statements. " << endl << endl;
    cout << endl << endl;
    
    

    cout << "Exitting program. Bye!" << endl;
    return (0);
}     


