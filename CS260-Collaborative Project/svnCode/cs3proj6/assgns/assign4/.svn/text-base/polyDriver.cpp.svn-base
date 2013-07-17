//  Driver to test implementation of the Polynomial class
//  Programmed by: Dr. Monisha Pulimood
//  Course: CSC 260
//  Semester: Fall 2012

#include "Polynomial.h"

using namespace std;

int main (void)
{
	Polynomial p1, p2, p3, p4;
	int x;
    int number = 5;
	
    //Test overloaded stream insertion and extraction operators 
	cout << "Enter Polynomial 1 from keyboard" << endl;
	cin >> p1;

	cout << "Polynomial 1 is:" << endl;
	cout << p1;
	
	cout << "Enter Polynomial 2 from a file" << endl;
    bool worked = true;
	string inFileName;
	ifstream inStr;
	
	do 
	{
		cout << "Enter name of file to read from: ";
		cin >> inFileName;
		
		inStr.open (inFileName.c_str());
		if (inStr.fail())
		{
			cerr << "Error opening file. Try again." << endl;
			inStr.clear();
			inStr.ignore(80, '\n');
			worked = false;
		}
		else 
			worked = true;
		
	} while (!worked);
	
    // Input file format is similar to how data is entered from keyboard
    // First number specifies the number of terms in the polynomial
    // Followed by pairs of numbers for each term 
    //          - first one is coefficient
    //          - second one is degree
    
    
	inStr >> p2;
	inStr.close();
    
	cout << "Polynomial 2 is:" << endl;
	cout << p2;
	
    // Test overloaded assignment operator
	cout << "After assigning p1 to p4, p4 is: " << endl;
	p4 = p1;
	cout << p4 << endl;
	
	cout << "Enter Polynomial 1" << endl;
	cin >> p1;
	
	cout << "Polynomial 1 is now:" << endl;
	cout << p1;
	
	cout << "Polynomial 4 is now: " << endl;
	cout << p4 << endl;
	
    // Test overloaded plus operator 
	cout << "Adding Polynomial 1 and Polynomial 2 gives:" << endl;
	p3 = p1 + p2;
	cout << p3 << endl;
	
	cout << "Adding Polynomial 1 and number gives:" << endl;
	p3 = p1 + number;
	cout << p3 << endl;

	cout << "Adding number and Polynomial 2 gives:" << endl;
	p3 = number + p2;
	cout << p3 << endl;
    
    // Test overloaded multiplication operator
	cout << "Multiplying Polynomial 1 and Polynomial 2 gives:" << endl;
	p3 = p1 * p2;
	cout << p3 << endl;
    
	cout << "Multiplying Polynomial 1 and number gives:" << endl;
	p3 = p1 * number;
	cout << p3 << endl;

	cout << "Multiplying number and Polynomial 2 gives:" << endl;
	p3 = number * p2;
	cout << p3 << endl;
    
    // Test polynomial evaluation
	cout << "Enter a value for x" << endl;
	cin >> x;
	
	cout << "Evaluating Polynomial 1 with " << x << " gives " << p1.evalPoly (x) << endl;
    
    // Test writing to a file 
    cout << "Writing Polynomial 3 to a file." << endl;
    // Output file format is similar to input file format so it can be read in as well
    // First number specifies the number of terms in the polynomial
    // Followed by pairs of numbers for each term 
    //          - first one is coefficient
    //          - second one is degree
    
    // Since behavior of display to screen is different from writing to a file
    //   we need different functions.
    p3.writeToFile();
    
    
	cout << "Bye!" << endl << endl;

	
	return 0;
}











