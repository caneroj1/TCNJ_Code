//
//  Generator.h
//  CSC260/Dr. Pulimood
//  Collaborative Project
//  Created by Joseph Canero on 11/26/12.
//
//

/* ********************************************
 
 This is the header file for the Generator module. This module is responsible for creating a random string of certain ASCII characters. The string is of a user-specified length. This fulfills the functionality of generating a random and secure password for the user to use. 
 
 ******************************************** */

#ifndef ____Generator__
#define ____Generator__

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

class Generator
{
private:
    int passLength; //length of the password
    
public:
    /* Default constructor
     Postcondition: a Generator class object is instantiated for use in generating random passwords
     Parameters: none
     */
    Generator ();
    /* generatePass
     Precondition: a random password needs to be generated
     Postcondition: the random password is generated and returned.
     Parameters: an int (for length of the password)
     Returns: a string
     */
    string generatePass (int);
};

#endif /* defined(____Generator__) */
