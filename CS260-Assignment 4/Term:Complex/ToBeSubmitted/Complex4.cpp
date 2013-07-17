//
//  Complex4.cpp
//  This is the implementation file for use with the ComplexDriver.cpp file.
//  It provides functionality for performing basic operations on a complex number.
//  Joe Canero
//  CSC260, Dr. Pulimood
//  Created by caneroj1 on 9/28/12.
//
//

#include "Complex4.h"
#include <iostream>

using namespace std;


Complex::Complex(int c, int d)
{
    coeff = c;
    deg = d;
 /* real = r;
    imag = i;
    deg = d; */
}
//Adds two complex numbers
//The degrees remain the same
//The coefficients are added
Complex Complex::add(const Complex& rhs)const
{
    Complex result(coeff, deg);
    if(deg == rhs.deg)
    {
        result.coeff = coeff + rhs.coeff;
        result.deg = deg;
        return result;
    }
    else
        return result;
}
//Subtracts two complex numbers
//The degrees remain the same
//The coefficients are subtracted
Complex Complex::subtract(const Complex& rhs)const
{
    /*Complex result;
    result.real = real - rhs.real;
    result.imag = imag - rhs.imag;
    return result;*/
}
//Multiplies two complex numbers
//Degrees are added
//Coefficients are multiplies
//i^2 -1
Complex Complex::operator*(const Complex& rhs)const
{
    Complex result;
    result.coeff = coeff * rhs.coeff*(-1);
    result.deg = deg + rhs.deg;
    return result;
}
//Prints a properly formatted Complex number
void Complex::print()
{
    //cout << coeff << endl << deg << endl;
    if(deg > 0 && coeff != 0)
        cout << coeff << "ix^" << deg << endl;
    if(deg == 0 && coeff != 0)
        cout << coeff << "i" << endl;
    if(coeff == 0 && deg != 0)
        cout << "0" << endl;
    if(coeff == 0 && deg == 0)
        cout << "0" << endl;
}

//Reads a complex number in from the keyboard
//Error checking is performed
void Complex::read()
{
    bool input = false;
    do {
        cout << "Enter a number for the coefficient: ";
        cin >> coeff;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << endl << "*************** That input is inappropriate ***************" << endl;
        }
        else
            input = true;
    } while (!input);
    
    do {
        cout << "Enter an integer for the degree: ";
        cin >> deg;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << endl << "*************** That input is inappropriate ***************" << endl;
        }
        else
            input = true;
    } while (!input);
    
}

//Overloaded operator+ to do the same thing as the add function
Complex Complex::operator+(const Complex& rhs) const
{
    Complex result(coeff, deg);
    if(deg == rhs.deg)
    {
        result.coeff = coeff + rhs.coeff;
        result.deg = deg;
        return result;
    }
    else
        return result;
}

//Overloaded operator+ to add an int to a Complex number
Complex Complex::operator+(int rhs) const
{
    return(Complex((rhs + real), imag));
}

//Overloaded operator+ to add a Complex number to an int
Complex operator+(int x, const Complex& rhs)
{
    return(Complex(x + rhs.real, rhs.imag));
}
