//  Joe Canero
//  Term.h
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/8/12.
//
//
#ifndef ____Term__
#define ____Term__

using namespace std;

class Term {
    
private:
    int coeff;
    int deg;
    
public:
    //*************************************************************************************
    //Constructor
    /*
     Parameterized default constructor for Term
     Accepts two integer values that will become the coefficient and degree of the Term, respectively
     */
    Term (int = 0, int = 0);
    
    //*************************************************************************************
    //Overloaded Add
    /*

     PARAMETERS: a const Term passed by reference
     PRECONDITION: the Term parameter takes the data from the right hand operand of the addition
     POSTCONDITION: the Terms are added if they have like degree and the result is returned
     */
    Term operator+(const Term&) const;
    
    //*************************************************************************************
    //Overloaded Multiplication
    /*

     PARAMETERS: a const Term passed by reference
     PRECONDITION: the term that is on the right side of the multiplication statement is the one passed in as the parameter
     POSTCONDITION: the two Terms are multiplied and the result is returned
     
     */
    Term operator*(const Term&) const;
    
    //*************************************************************************************
    //Overloaded Multiplication
    /*
     
     PARAMETERS: an integer
     PRECONDITION: the integer value on the right side of the multiplication statement becomes the int parameter
     POSTCONDITION: the Term has its coefficient multiplied by the parameter and the result is returned
     
     */
    Term operator*(int) const;
    
    //*************************************************************************************
    //Overloaded Assignment
    /*
     
     PARAMETERS: a const Term passed by reference
     PRECONDITION: the Term that is on the right side of the assignment statement is the one passed in as the parameter
     POSTCONDITION: the calling Term becomes the Term that was passed in. The result is returned
     
     */
    Term operator=(const Term&);
    
    //*************************************************************************************
    //Input Term
    /*
     
     PARAMETERS: none
     PRECONDITION: the calling Term has its data written from the keyboard
     POSTCONDITION: the calling Term's data has been overwritten successfully
     
     */
    Term inputTerm();
    
    //*************************************************************************************
    //Return coefficient of Term
    /*
     
     PARAMETERS: none
     PRECONDITION: the calling Term is valid
     POSTCONDITION: the calling Term's coefficient is returned
     
     */
    int returnCo() const;
    
    //*************************************************************************************
    //ostream& displayTerm(ostream&);
    /*
     
     PARAMETERS: an ostream object passed by reference and a Term object passed by reference
     PRECONDITION: the calling object is cout and is passed in as the first parameter and the Term to be output is passed in as the second parameter
     POSTCONDITION: the Term is successfully output to the standard output stream
     
     */
    friend ostream& operator<<(ostream&, Term&);
    
    //*************************************************************************************
    //evalTerm
    /*
     
     PARAMETERS: a double
     PRECONDITION: the Term is valid and the value passed in becomes the first parameter
     POSTCONDITION: the variable part of the Term becomes the value passed in and the Term is evaluated with that value and the result is returned
     
     */
    double evalTerm(double) const;
    
    //*************************************************************************************
    //returnDegree
    /*
     
     PARAMETERS: none
     PRECONDITION: the Term is valid
     POSTCONDITION: the Term's degree is returned
     
     */
    int returnDegree() const;
};

//#include <iostream>

#endif /* defined(____Term__) */

