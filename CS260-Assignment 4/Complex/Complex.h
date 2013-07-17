//
//  Complex.h
//  
//
//  Created by caneroj1 on 9/28/12.
//
//

#ifndef ____Complex__
#define ____Complex__

#include <iostream>

#endif /* defined(____Complex__) */

class Complex {
private:
    int real;
    int imag;
    
public:
    Complex (int = 0, int = 0);
    Complex add (const Complex&) const;
    Complex subtract (const Complex&) const;
    Complex multiply (const Complex&) const;
    void divide (const Complex&) const;
    Complex findConjugate (const Complex&) const;
    
    
    void print();
    void read();
};