// Program that illustrates the use of virtual functions and polymorphism.
// Programmed By: Monisha Pulimood for use in CSC 260
//                
// DO: Add maintenance information 
////////////////
//
// HourlyWorker.cpp
// Member function definitions for class HourlyWorker

#include <iostream>
#include <iomanip>
#include <sstream>
#include "HourlyWorker.h"


// Constructor for class HourlyWorker
HourlyWorker::HourlyWorker (const string first, const string last,
			    float initHours, float initWage, float initTax)
    : Employee (first, last)   // call base-class
{ 
    //DO: add the code that indicates to the user that this constructor has been called
    //DO: add code to initialize the attributes
}

// DO: add definitions for calcGross(), calcTax() and calcDedn()

// Print the HourlyWorker's name and pay
string HourlyWorker::object2string() 
{
    ostringstream os;
    
    os << Employee::object2string();   // call base-class print function
    
    os << " is an hourly worker with pay of"
       << " $" <<  setiosflags(ios::showpoint | ios::fixed)
       << setprecision(2) 
       << calcIncome();
    return os.str();
}

//DO: Add other needed methods - in each include a display statement that indicates that the method was called

