//  Skeleton of header file for functions to calculate the final score of a competitor
//  For use in lab exercise
//  Programmed by: Dr. Monisha Pulimood

//  ** Modify the maintenance documentation as appropriate ***
// Name: *** Put your name here
// Course: 
// Semester: 
// Instructor: Dr. Pulimood
// 
// Description: *** put a brief description of the program here
// Filename: scoreFunctions.h
// Last modified on: September 18, 2012


#include <iostream>
#include <cmath>

using namespace std;
const int MAXNUM = 10;
const double FACTOR = 0.6;

//-----------------------------------------------------------------------------------------
//  function:  calcFinalScore ()
//             Calculates the final score for a competitor in a sports event.
//	Parameters:	
//    input: deg; float; degree of difficulty
//    input: num; int; number of judges
//    input: scr; array; float; scores of all judges
//	  output: finScr; float; final score for competitor 
//  Return Value:
//    bool; whether function succeeded or not
//    
//	Pre-conditions: deg, num, and scr have valid values  
//                 i.e. 1.2 <= deg <= 3.8
//                      5 <= num <= 10
//                      0 <= scr[i] <= 10
//  Post-condition: The highest and lowest scores are discarded and the remaining scores 
//                  are used to calculate the final score that is returned as an output 
//                  parameters. If the function succeeds, it returns 'true', otherwise
//                  it returns 'false' 
//-----------------------------------------------------------------------------------------

// *** DO: insert the prototype for calcFinalScore here  



//-----------------------------------------------------------------------------------------
//  function:  getValidFloat ()
//             Ensures that the user does not input data of the incorrect data type.
//	Parameters:	
//    input: none
//  Return Value:
//	  float: valid float value 
//    
//	Pre-conditions: none
//  Post-condition: Data of float type is returned. 
//-----------------------------------------------------------------------------------------

float getValidFloat (void);

//-----------------------------------------------------------------------------------------
//  function:  getValidInt ()
//             Ensures that the user does not input data of the incorrect data type.
//	Parameters:	
//    input: none
//  Return Value:
//	  int: valid integer value 
//    
//	Pre-conditions: none
//  Post-condition: Data of integer type is returned. 
//-----------------------------------------------------------------------------------------

// *** DO: insert the prototype for getValidInt here  




