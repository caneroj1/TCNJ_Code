//
//  Complex.h
//  This is the header file for use in conjunction with the ComplexDriver.cpp file and the
//  Complex.cpp file
//  Joe Canero
//  CSC260, Dr. Pulimood
//  Created by caneroj1 on 9/28/12.
//
//

#ifndef ____Complex__
#define ____Complex__

#include <iostream>

#endif /* defined(____Complex__) */

class Complex {
private:
    int real; //real constant of a complex number
    int imag; //imaginary coefficient
    
public:
    /*
     Constructor for Complex class. Accepts two int parameters or can instantiate nonprovided 
     parameters as 0
     PRECONDITION: User wants to instantiate a complex number object.
     POSTCONDITION: Object is instantiated
     */
    Complex (int = 0, int = 0);
    /*
     Member function to add an integer to the real constant of the calling object
     PRECONDITION: User wants an integer added to the real constant.
     POSTCONDITION: Integer has been added and resulting complex number is returned.
     */
    Complex add (int) const;
    /*
     Member function to add two complex numbers
     PRECONDITION: User wants to add two complex numbers
     POSTCONDITION: Real constants and imaginary coefficients are added and the resulting
     complex number is returned
     */
    Complex add (const Complex&) const;
    /*
     Member function to subtract two complex numbers
     PRECONDITION: User wants to subtract two complex numbers
     POSTCONDITION: Real constants and imaginary coefficients are subtracted and the resulting
     complex number is returned
     */
    Complex subtract (const Complex&) const;
    /*
     Member function to multiply two complex numbers
     PRECONDITION: User wants to multiply two complex numbers
     POSTCONDITION: The complex numbers multiplied using the FOIL method and the resulting
     comlex number is returned.
     */
    Complex multiply (const Complex&) const;
    /*
     Member function to divide two complex numbers
     PRECONDITION: User wants to divide two complex numbers
     POSTCONDITION: The complex numbers are divided. To divide two complex numbers,
     the conjugate of the denominator must be found. Next, the numerator and denominator
     are both multiplied by the conjugate. The resulting complex number is printed.
     */
    void divide (const Complex&) const;
    /*
     Member function to find a complex number's conjugate
     PRECONDITION: User wants to divide two complex numbers, complex numbers 
     are valid
     POSTCONDITION: The conjugate is found and returned
     */
    Complex findConjugate (const Complex&) const;
    /*
     Member function to access the real constant of a complex number
     PRECONDITION: User requires access to the real constant
     POSTCONDITION: The constant is returned
     */
    int getReal (const int&) const;
    /*
     Member function to access the imaginary coefficient of a complex number
     PRECONDITION: User requires access to the imaginary coefficient
     POSTCONDITION: The required coefficient is returned
     */
    int getImag (const int&) const;
    /*
     Overloaded member function to add two complex numbers
     PRECONDITION: User wants to add a complex number and both parameters
     are complex numbers
     POSTCONDITION: The sum is returned
     */
    Complex operator+ (const Complex&)const;
    /*
     Overloaded member function to add a complex number to some integer
     PRECONDITION: User wants to add an integer and one parameter
     is a complex number and the other is an integer.
     POSTCONDITION: The sum is returned
     */
    Complex operator+ (int) const;
    /*
     Member function to properly format and display a complex number
     PRECONDITION: User wants to display the complex number. It is a valid 
     number
     POSTCONDITION: The complex number is printed to the screen
     */
    void print();
    /*
     Member function to read complex number information from the user
     PRECONDITION: User wants to input the complex number
     POSTCONDITION: The complex number is created
     */
    void read();
    /*
     Friend function to add a complex number to an integer
     PRECONDITION: User wants to add a complex number to an integer. The
     complex number is valid
     POSTCONDITION: The sum is computed and the complex number that results
     is returned
     */
    friend Complex operator+ (int, const Complex&);
};
