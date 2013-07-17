//
//  Complex.cpp
//  This is the implementation file for use with the ComplexDriver.cpp file.
//  It provides functionality for performing basic operations on a complex number.
//  Joe Canero
//  CSC260, Dr. Pulimood
//  Created by caneroj1 on 9/28/12.
//
//

#include "Complex.h"
#include <iostream>

using namespace std;


Complex::Complex(int r, int i)
{
    real = r;
    imag = i;
}

Complex Complex::add(const Complex& rhs)const
{
    Complex result;
    result.real = real + rhs.real;
    result.imag = imag + rhs.imag;
    return result;
}

Complex Complex::subtract(const Complex& rhs)const
{
    Complex result;
    result.real = real - rhs.real;
    result.imag = imag - rhs.imag;
    return result;
}

Complex Complex::multiply(const Complex& rhs)const
{
    int term1 = 0;
    int term2 = 0;
    int term3 = 0;
    int term4 = 0;
    Complex result;
    
    term1 = real * rhs.real;
    term2 = real * rhs.imag;
    term3 = imag * rhs.real;
    term4 = imag * rhs.imag;
    
    result.real = term1 + term4*(-1);
    result.imag = term2 + term3;
    return result;
}

void Complex::divide(const Complex& rhs)const
{
    Complex conjug;
    Complex numerator;
    Complex denom;
    conjug = rhs.findConjugate(rhs);
    numerator = multiply(conjug);
    denom = rhs.multiply(conjug);
    cout << "The quotient of your two complex numbers is: " << endl;
    numerator.print();
    cout << "___________" << endl;
    denom.print();
    cout << endl;
}

Complex Complex::findConjugate(const Complex& rhs) const
{
    Complex result;
    result.real = rhs.real;
    result.imag = rhs.imag*-1;
    return result;
}

void Complex::print()
{
    if(imag > 0 && real != 0)
        cout << real << " + " << imag << "i" << endl;
    if(imag < 0 && real != 0)
        cout << real << " - " << imag*(-1) << "i" << endl;
    else
    {
        if(imag == 0 && real != 0)
            cout << real;
        if(real == 0 && imag != 0)
        {
            if(imag > 0)
                cout << imag + "i" << endl;
            if(imag < 0)
                cout << imag*(-1) + "i" << endl;
        }
        if(real == 0 && imag == 0)
            cout << "0" << endl;
    }
}

void Complex::read()
{
    bool input = false;
    do {
        cout << "Enter an integer for the real constant: ";
        cin >> real;
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
        cout << "Enter an integer for the imaginary coefficient: ";
        cin >> imag;
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

Complex Complex::operator+(const Complex& rhs) const
{
    Complex result;
    result.real = real + rhs.real;
    result.imag = imag + rhs.imag;
    return result;
}

Complex Complex::operator+(int rhs) const
{
    return(Complex((rhs + real), imag));
}

Complex Complex::add(int rhs) const
{
    return(Complex((rhs + real), imag));
}

Complex operator+(int x, const Complex& rhs)
{
    return(Complex(x + rhs.real, rhs.imag));
}
/*Complex add (int x, const Complex& rhs)
{
    return(Complex(x + rhs.real, rhs.imag));
}*/
