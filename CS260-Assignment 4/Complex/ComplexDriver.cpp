//
//  ComplexDriver.cpp
//  
//
//  Created by Joseph Canero on 9/30/12.
//
//

#include "complex.cpp"
#include <iostream>

using namespace std;

int main()
{
    Complex number1;
    Complex number2;
    char userI;
    char contin = 'y';
    char contout = 'n';
    bool success = false;
    bool exit;
    bool looper = false;
    
    cout << endl << "*****************************" << endl << "This program multiplies, adds, subtracts, and divides complex numbers." << endl << "*****************************" << endl;
    
    do {
        exit = true;
        
        cout << endl << "Number 1" << endl;
        number1.read();
        cout << "Number 2" << endl;
        number2.read();
        
        cout << "Complex Number 1: ";
        number1.print();
        cout << endl;
        
        cout << "Complex Number2: ";
        number2.print();
        cout << endl;
        
        cout << "This is the product of your two complex numbers: ";
        Complex result = number1.multiply(number2);
        result.print();
        cout << endl;
        
        cout << "This is the sum of your two complex numbers: ";
        result = number1.add(number2);
        result.print();
        cout << endl;
        
        cout << "This is the difference between your two complex numbers: ";
        result = number1.subtract(number2);
        result.print();
        cout << endl;
        
        number1.divide(number2);
        
        do
        {
            do {
                cout << "Would you like to continue? (y/n)" << endl;
                cin >> userI;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(800, '\n');
                    success = false;
                }
                else
                    success = true;
            }while(!success);
            
            if(userI == contin)
            {
                looper = true;
                exit = false;
            }
            if(userI == contout)
            {
                exit = true;
                looper = true;
            }
            if(userI != contin && userI != contout)
            {
                looper = false;
                cin.ignore(800, '\n');
            }
            
        }while(!looper);
        
    }while(!exit);
    
    return 0;
}

