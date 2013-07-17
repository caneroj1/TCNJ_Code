//
//  Complex.cpp
//  This is the implementation file for use with the ComplexDriver.cpp file.
//  It provides functionality for performing basic operations on a complex number.
//  Joe Canero
//  CSC260, Dr. Pulimood
//  Created by caneroj1 on 9/28/12.
//
//

#include "Complex4Temp.h"

using namespace std;

Complex::Complex(int r, int i)
{
    real = r;
    imag = i;
}

ostream& operator<< (ostream& outs, const Complex& comp)
{
    if(comp.imag > 0 && comp.real != 0)
        outs << "("<< comp.real << " + " << comp.imag << "i)";
    if(comp.imag < 0 && comp.real != 0)
        outs << "(" << comp.real << " - " << comp.imag*(-1) << "i)";
    else
    {
        if(comp.imag == 0 && comp.real != 0)
            outs << comp.real;
        if(comp.real == 0 && comp.imag != 0)
        {
            if(comp.imag > 0)
                outs << "(" << comp.imag + "i)";
            if(comp.imag < 0)
                outs << "(-" << comp.imag*(-1) + "i)";
        }
        if(comp.real == 0 && comp.imag == 0)
            outs << "0";
    }
    
    return outs;
}

istream& operator>> (istream& ins, Complex& comp)
{
    bool input = false;
    do {
        cout << "Enter an integer for the real constant: ";
        ins >> comp.real;
        if(ins.fail())
        {
            ins.clear();
            ins.ignore(80, '\n');
            cerr << endl << "*************** That input is inappropriate ***************" << endl;
        }
        else
        {
            input = true;
        }
    } while (!input);
    
    do {
        cout << "Enter an integer for the imaginary coefficient: ";
        ins >> comp.imag;
        if(ins.fail())
        {
            ins.clear();
            ins.ignore(80, '\n');
            cerr << endl << "*************** That input is inappropriate ***************" << endl;
        }
        else
            input = true;
    } while (!input);
    return ins;
}

ifstream& operator>> (ifstream& infs, Complex& comp)
{
    bool input = false;
    do {
        infs >> comp.real;
        if(infs.fail())
        {
            infs.clear();
            infs.ignore(80, '\n');
        }
        else
        {
            input = true;
        }
    } while (!input);
    
    do {
        infs >> comp.imag;
        if(infs.fail())
        {
            infs.clear();
            infs.ignore(80, '\n');
        }
        else
            input = true;
    } while (!input);
    return infs;
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

Complex operator+(int x, const Complex& rhs)
{
    return(Complex(x + rhs.real, rhs.imag));
}

Complex Complex::operator*(const Complex& rhs) const
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

Complex Complex::operator*(int rhs) const
{
    Complex result(real*rhs, imag*rhs);
    return result;
}

Complex Complex::operator*(double rhs) const
{
    Complex result(real*rhs, imag*rhs);
    return result;
}

Complex operator* (int lhs, const Complex& rhs)
{
    Complex result(rhs.real * lhs, rhs.imag*lhs);
    return result;
}

Complex Complex::operator= (const Complex& rhs)
{
    real = rhs.real;
    imag = rhs.imag;
    return *this;
}

bool Complex::operator== (int rhs) const
{
    if(imag == 0)
    {
        if(real == rhs)
            return true;
        if(real != rhs)
            return false;
    }
    if(imag != 0)
        return false;
    
    else
        return false;
}

bool Complex::operator!= (int rhs) const
{
    if(imag == 0)
    {
        if(real == rhs)
            return false;
        if(real != rhs)
            return true;
    }
    if(imag != 0)
        return true;
    
    else
        return false;
}

bool Complex::operator> (int rhs) const
{
    if(imag == 0)
    {
        if (real == rhs)
            return false;
        if (real > rhs)
            return true;
        if (real < 0)
            return false;
    }
    
    if(imag != 0)
    {
        if (real == rhs)
            return false;
        if (real > 0)
            return true;
        if (real < 0)
            return false;
    }
    
    return false;
}

bool Complex::operator< (int rhs) const
{
    if(imag == 0)
    {
        if (real == rhs)
            return false;
        if (real > rhs)
            return false;
        if (real < rhs)
            return true;
    }
    
    if(imag != 0)
    {
        if (real > rhs)
            return false;
        if (real == rhs)
            return false;
        if (real < rhs)
            return true;
    }
    
    return false;
}