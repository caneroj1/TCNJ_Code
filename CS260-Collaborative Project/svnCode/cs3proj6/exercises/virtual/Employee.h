// Program that illustrates the use of virtual functions and polymorphism.
// Programmed By: Monisha Pulimood for use in CSC 260
//               
// DO: Add maintenance information 
//////////////////////
//
// Employee.h
// Definition of class Employee

#if !defined (EMPLOY_H)
#define EMPLOY_H


#include <string>
#include <sstream>

using namespace std;

class Employee
{
private:
	string firstName;
	string lastName;
public:
	// DO: add code as needed to the prototypes of methods to ensure that the 
	//     appropriate overriding method (from dervide class) is invoked 	 
	//     depending on the type of the calling object
	
	Employee (const string, const string);  // constructor
	string getFirstName();
	string getLastName();
	
	float calcIncome();
	
	// DO: add prototypes for calcGross(), calcTax(), and calcDedn() 
	
	// converts the output to a string 
	string object2string ();
	
	~Employee ();         // destructor
};

#endif
