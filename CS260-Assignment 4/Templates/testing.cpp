//
//  testing.cpp
//  
//
//  Created by Joseph Canero on 10/24/12.
//
//

#include "testing.h"
#include "PolynomialTemp.cpp"
#include "Complex4Temp.cpp"

using namespace std;

int main()
{
    Polynomial<int> p1;
    Polynomial<int> p2;
    
    cout << "Input the first poly:" << endl;
    cin >> p1;
    cout << "Input the second poly:" << endl;
    cin >> p2;
    
    cout << "FIRST POLY: " << endl << p1 << "SECOND POLY: " << endl << p2 << endl;
    
    Polynomial<int> p3;
    p3 = p1 + p2;
    
    cout << "After adding them, the result is: " << endl;
    
    cout << p3 << endl;
    
    cout << "Adding an integer to POLY 1." << endl;
    
    p3 = p1 + 6;
    
    cout << "Result is: " << endl << p3 << endl;
    
}