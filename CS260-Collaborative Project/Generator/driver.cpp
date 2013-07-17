//
//  driver.cpp
//  
//
//  Created by Joseph Canero on 11/26/12.
//
//

#include "driver.h"

using namespace std;

int main ()
{
    Generator gen;
    
    int x;
    
    cout << "How long do you wish your password to be? ";
    cin >> x;
    cout << endl;
    
    string password = gen.generatePass(x);
    
    cout << "The password is: " << password << endl;
}