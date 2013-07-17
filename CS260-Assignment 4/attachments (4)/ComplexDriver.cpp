//  ComplexDriver.cpp
//  Driver program to test the implementation of the 
//  Complex class
//  For use in class
//  Created by: Dr. Monisha Pulimood
//  Modified by: Joe Canero
//  ** Add maintenance documentation where appropriate **

#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex comp1;      // some complex numbers for our demonstration
    Complex comp2 (5, 7);
    Complex comp3;
	
    cout << "Input data for Complex number comp1: " << endl;
    comp1.read();                                           //Asks for user input for complex number comp1.
    cout << "The Complex number comp1 is ";
    comp1.print();                                          //Displays comp1 with appropriate formatting for complex
                                                            //numbers
    cout << endl;

	cout << "The Complex number comp2 is ";
    comp2.print();                                          //Displays comp2 with appropriate formatting for complex
                                                            //numbers
    cout << endl;
		
	cout << "Adding comp1 and comp2 using member function add results in: ";
	//comp3 = comp1.add(comp2);                               //This adds comp1 and comp2 using the member function to
    comp3 = comp1 + comp2;                                    //add two complex numbers
    comp3.print();                                            //Displays comp3 with appropriate formatting for complex
                                                              //numbers
    cout << endl;
    
    cout << "Adding comp1 and comp2 using nonmember function add results in: "; 
	//comp3 = add(comp1,comp2);                               //This adds two complex numbers using the nonmember
    comp3 = comp1 + comp2;                                    //defined as a friend of the Complex class
    comp3.print();                                            //Displays comp3 with appropriate formatting for complex
                                                              //numbers
    cout << endl;
			
    cout << "Adding 5 and comp2 using nonmember function add results in: ";
	//comp3 = add(5,comp2);                                   //This adds an integer to a complex number using the
    comp3 = 5 + comp2;                                        //nonmember function to add an integer to a complex
                                                              //number's real constant.
    comp3.print();
    cout << endl;
     
    
	cout << "Exiting program. Bye." << endl << endl;
	return 0;
}
