//
//  numberConverter.h
//  
//
//  Created by Joseph Canero on 9/1/13.
//
//

#ifndef ____numberConverter__
#define ____numberConverter__

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void checkUserInput(char &userIn);
void checkUserNumberSystem(double &system, int);
bool numberIsValid(string, int);
int numberHasDecimal(string);
double convertStringToDecInt(string, double);

//variables for handling of user input
double originalBase = 0; //starting number system
double newBase = 0; //ending number system
char cont = 'y'; //will the user continue converting?
char end = 'n';
char userIn = 'a';
string number = ""; //the user's number that will be converted

#endif /* defined(____numberConverter__) */
