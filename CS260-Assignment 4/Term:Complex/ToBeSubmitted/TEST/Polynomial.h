//  Joe Canero
//  Polynomial.h
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/9/12.
//
//

#ifndef ____Polynomial__
#define ____Polynomial__
#include <iostream>
#include <fstream>
#include "Term.cpp"

using namespace std;

const int MAX_TERMS = 10; //the max size of the array of Terms

class Polynomial {
    
private:
    Term polyArr[MAX_TERMS]; //the Term array
    int tCount; // the amount of Terms in each Polynomial
    
public:
    //*************************************************************************************
    /*
     Constructor for Polynomial
     This is the default constructor
     
     It sets the Term Count of the Polynomial equal to 0
     
     
     */
    Polynomial ();
    
    //*************************************************************************************
    /*
    Parameterized constructor for Polynomial.
     
     Accepts two integer parameters
     
     Calls the parameterized constructor from Term to set the first parameter as the coefficient and the second as the degree
     
     
     */
    Polynomial (int, int);
    
    //*************************************************************************************
    /*
     Overloaded+
     PARAMETERS: a const Polynomial passed by reference
     PRECONDITION: the calling object is a Polynomial, and the parameter is the other Polynomial to be added
     POSTCONDITION: the Polynomials have been successfully added and the result is returned
     
     */
    Polynomial operator+ (const Polynomial&) const;
    
    //*************************************************************************************
    /*
     Overloaded+
     PARAMETERS: an integer
     PRECONDITION: the calling object is a Polynomial, and the parameter is the integer
     POSTCONDITION: the integer has been added to the Polynomial and the result is returned
     
     */
    Polynomial operator+ (int) const;
    
    //*************************************************************************************
    /*
     Overloaded+
     PARAMETERS: an integer and a const Polynomial passed by reference
     PRECONDITION: this is a friend function, and so it is called by the integer which becomes the first parameter and the second parameter becomes the Polynomial to be
     added
     POSTCONDITION: the int has been added to the Polynomial and the result is returned
     
     */
    friend Polynomial operator+ (int, const Polynomial&);
    
    //*************************************************************************************
    /*
     Overloaded*
     PARAMETERS: a const Polynomial passed by reference
     PRECONDITION: the calling object is a polynomial and the other operand becomes the parameter to be used during the multiplication
     POSTCONDITION: the two Polynomials have been multiplied and the result is returned
     
     ------------------------------------NOTE----------------------------------------------
     As the Polynomial can only store a maximum of 10 Terms, the multiplication stops once the term count is 10.
     Once the multiplication of the two Polynomials has concluded, the resulting Polynomial is simplified and sorted.
     If the Polynomial, after being multiplied, contains Terms of like degree, they will be simplified (i.e. added), which in the case of a 10-Term Polynomial may
     result in the returned Polynomial having less than 10 Terms. This is not an error, it is just the simplified version of the 10-Term Polynomial.
     
     */
    Polynomial operator* (const Polynomial&) const;
    
    //*************************************************************************************
    /*
     Overloaded*
     PARAMETERS: an integer
     PRECONDITION: the calling object is the Polynomial and the integer operand becomes the parameter
     POSTCONDITON: the calling Polynomial has all of its Terms multiplied by the integer and the result is returned
     
     */
    Polynomial operator* (int) const;
    
    //*************************************************************************************
    /*
     Overloaded*
     PARAMETERS: an integer, which is the calling data type seeing how this is a friend function, and a const Polynomial passed by reference
     PRECONDITION: the integer operand is stored as the first parameter and the Polynomial operand is stored as the second parameter
     POSTCONDITION: the Polynomial has all of its Terms multiplied by the integer and the result is returned.
     
     */
    friend Polynomial operator* (int, const Polynomial&);
    
    //*************************************************************************************
    /*
     Operator>>
     This is an overloaded method whose primary purpose is to replace the creation of a function that focuses on reading input from a file.
     PARAMETERS: an ifstream object passed by reference and a Polynomial passed by reference
     PRECONDITION: the file to be read from is opened successfully
     POSTCONDITION: the Polynomial passed by reference has its Terms altered according to the data in the file. The ifstream object is returned in case additional processing is needed
     
     */
    friend ifstream& operator>> (ifstream&, Polynomial&);
    
    //*************************************************************************************
    /*
     writeToFile
     This writes the Polynomial to a file
     PARAMETERS: none
     PRECONDITION:
     POSTCONDITION: the file to be written to is contained within the function, so no user input there is needed. The Polynomial is written to the output file in a format similar to how a Polynomial would be read in
     
     */
    void writeToFile () const;
    
    //*************************************************************************************
    /*
     operator=
     PARAMETERS: a const Polynomial passed by reference
     PRECONDITION: the Polynomial that is the operand on the right side becomes the first parameter
     POSTCONDITION: the calling Polynomial has its data altered according the Polynomial that is passed in. The calling object itself is returned
     
     */
    Polynomial operator= (const Polynomial&);
    
    //*************************************************************************************
    /*
     operator=
     PARAMETERS: an integer
     PRECONDITION: the integer on the right side becomes the first parameter
     POSTCONDITION: the calling Polynomial is completely overwritten to store a single Term of coefficient parameter integer and degree 0
     
     */
    Polynomial operator= (int);
    
    //*************************************************************************************
    /*
     simplifyTerms
     PARAMETERS: a Polynomial passed by reference. This is a friend function
     PRECONDITION: The polynomial passed in by reference is the one to be simplified, and it should be the one calling the function
     POSTCONDITION: the calling Polynomial will be used in the processing. It will be simplified and the results of the simplification will be stored in a Polynomial result which will be returned
     Simplification means the combination of Terms of like degree
     
     */
    friend Polynomial simplifyTerms (Polynomial&);
    
    //*************************************************************************************
    /*
     sortPoly
     PARAMETERS: a Polynomial passed by reference. This is a friend function
     PRECONDITION: the polynomial passed in by reference is the one to be sorted and it should be the one calling the function
     POSTCONDITION: the calling Polynomial has its data sorted as it was passed in to this function by reference
     The sorting algorithm used for this function is Insertion Sort
     
     */
    friend Polynomial& sortPoly (Polynomial&);
    
    //*************************************************************************************
    /*
     operator<<
     This is a friend function
     PARAMETERS: an ostream object passed by reference and a Poylnomial object passed by reference
     PRECONDITION: the calling object is actually cout. That is passed in as the first parameter and the Polynomial to be output is passed in as the second parameter
     POSTCONDITION: the Polynomial passed in is output to the screen and the ostream object is returned in case additional outputting is required

     */
    friend ostream& operator<< (ostream&, Polynomial&);
    
    //*************************************************************************************
    /*
     operator>>
     This is a friend function
     PARAMETERS: an istream object passed by reference and Polynomial object passed by reference
     PRECONDITION: the calling object is cin. It is passed in as the istream parameter and the Polynomial that will have its terms read in from te keyboard is the second Parameter
     POSTCONDITION: the Polynomial has its data read in and the istream object is returned
     
     */
    friend istream& operator>> (istream&, Polynomial&);
    
    //*************************************************************************************
    /*
     evalPoly
     PARAMETERS: a double
     PRECONDITION: the value that is passed in will become the value of the variables in the Polynomial
     POSTCONDITION: the Polynomial is evaluated with the variable in each term becoming the double passed in. The result is returned
     
     */
    double evalPoly (double) const;
};




#include <iostream>

#endif /* defined(____Polynomial__) */
