// Program that illustrates the use of virtual functions and polymorphism.
// Programmed By: Monisha Pulimood for use in CSC 260,
//                
// DO: Add maintenance information 
////////////////////////////////
//
// Employee.cpp
// Member function definitions for class Employee

#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"


using namespace std;

// parameterized constructor  
Employee::Employee (const string first, const string last)
{
  firstName = first;
  lastName = last;
  cout << "Invoked Employee constructor for instance " << firstName << " " << lastName << endl;
}

// DO: add definitions for getFirstName() and getLastName()

float Employee::calcIncome()
{
    return (calcGross() - calcTax() - calcDedn());
}

// DO: add definitions for calcGross(), calcTax() and calcDedn()

string Employee::object2string () 
{ 
    ostringstream os;
    os << "Employee " << firstName << " " << lastName;
    return os.str();
}

Employee::~Employee ()
{
    cout << "Invoked Employee destructor for object: " << firstName << " " << lastName << endl;
}


