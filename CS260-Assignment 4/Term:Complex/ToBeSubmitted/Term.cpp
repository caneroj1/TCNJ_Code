//  Joe Canero
//  Term.cpp
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/9/12.
//
//

#include <iostream>
#include "Term.h"
#include <cmath>

using namespace std;

//*************************************************************************************
Term::Term(int c, int d)
{
    //This sets the coefficient and degree of the term equal to the passed in data
    
    coeff = c;
    if(d >= 0)
        deg = d;
    if(d < 0)
        deg = d * -1;
}

//*************************************************************************************
Term Term::operator+(const Term& rhs) const
{
    //This adds two Terms if they have the same degree
    
    Term result(0,0);
    if(deg == rhs.deg)
    {
        cout << "Addition is being done." << endl;
        Term result(coeff + rhs.coeff, deg);
        cout << result << endl;
    }
    
    return result;
}

//*************************************************************************************
Term Term::operator*(const Term& rhs) const
{
    //This multiplies two Terms
    //It multiplies the coefficients
    //The degrees are added
    
    Term result(coeff*rhs.coeff, deg + rhs.deg);
    return result;
}

//*************************************************************************************
Term Term::operator*(int rhs) const
{
    //This multiplies the coefficient of a Term by the integer passed in
    //The degree remains the same
    
    Term result(coeff * rhs, deg);
    return result;
}
//*************************************************************************************
Term Term::inputTerm()
{
    //Reads in Term data from the keyboard
    
    //Error checking is performed
    
    //Even though the cout asks for the Degree to be >= 0, a negative value can be entered. If a negative degree is entered, the constructor simply multiplies by -1
    
    bool success = false;
    do {
        cout << "Enter the coefficient for the term: ";
        cin >> coeff;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "That input is invalid." << endl;
        }
        else
            success = true;
    } while (!success);
    
    do {
        cout << "Enter the degree for the term (Degree >= 0): ";
        cin >> deg;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "That input is invalid." << endl;
            success = false;
        }
        else
            success = true;
    }while (!success);
    
    if(coeff == 0)
    {
        Term result(0,0);
        return result;        
    }
    else
    {
        Term result(coeff, deg);
        return result;
    }

}

//*************************************************************************************
ostream& operator<<(ostream& outs, Term& rhs)
{
    //This outputs the values of the Term
    
    if(rhs.coeff != 0 && rhs.deg != 0)
        outs << rhs.coeff << "x^" << rhs.deg << " ";
    if(rhs.coeff == 0 && rhs.deg != 0)
        outs << rhs.coeff;
    if(rhs.coeff == 0 && rhs.deg == 0)
        outs << rhs.coeff;
    if(rhs.coeff != 0 && rhs.deg == 0)
        cout << rhs.coeff;
    return outs;
}

//*************************************************************************************
double Term::evalTerm(double num) const
{
    //Evalulates the term with the passed in double
    
    return (coeff * pow(num, deg));
}

//*************************************************************************************
int Term::returnDegree() const
{
    //returns the degree of the Term so it can be used for processing
    
    return deg;
}

//*************************************************************************************
Term Term::operator=(const Term& rhs)
{
    //Makes a term equal to the Term passed in
    //The coefficient and degree are changed
    
    coeff = rhs.coeff;
    deg = rhs.deg;
    return *this;
}

int Term::returnCo() const
{
    //returns the coefficient of the Term so it can be used for processing
    return coeff;
}