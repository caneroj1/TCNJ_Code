// Program that illustrates the use of pointers.
// Programmed By: Monisha Pulimood for use in CSC 260, 
// DO: Add maintenance information 

#include <iostream>
#include "ptrFunctions.h"

using namespace std;


// Function that takes an array as a parameter

void intArrayManip (int matrix[], int numElems)
{
    int index;

    for (index = 0; index < numElems; ++index)
        matrix [index] = 100 + index;

    cout << "\nThe array is referenced in the function intArrayManip ()" << endl;
	
	
    cout << "Leaving function intArrayManip ()" << endl << endl;
}


