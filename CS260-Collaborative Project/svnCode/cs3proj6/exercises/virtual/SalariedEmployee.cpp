// Program that illustrates the use of virtual functions and polymorphism.
// Programmed By: Monisha Pulimood for use in CSC 260
//                
// DO: Add maintenance information 
////////////////
//
// SalariedEmployee.cpp
// Member function definitions for class SalariedEmployee

#include <iostream>
#include <iomanip>
#include <sstream>
#include "SalariedEmployee.h"


// DO: add constructor for class SalariedEmployee
// DO: include code that indicates this constructor was called


// DO: add definitions for calcGross(), calcTax() and calcDedn()

// Print the SalariedEmployee's name and pay
string SalariedEmployee::object2string() 
{
    ostringstream os;
    
    os << Employee::object2string();   // call base-class print function
    
    os << " is a salaried employee with net income "
       << " $" <<  setiosflags(ios::showpoint | ios::fixed)
       << setprecision(2) << calcIncome();
    
    return os.str();
}

//DO: Add other needed methods - in each include a display statement that indicates that the method was called


