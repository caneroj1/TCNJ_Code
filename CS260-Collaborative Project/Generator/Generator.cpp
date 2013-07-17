//
//  Generator.cpp
//  
//
//  Created by Joseph Canero on 11/26/12.
//
//

#include "Generator.h"

Generator::Generator ()
{
}

string Generator::generatePass (int len)
{
    passLength = len;
    string password;
    
    if (passLength > 0) {
        char passLetter[passLength + 1];
        
        srand (time(NULL));
        
        for (int i = 0; i < passLength; i++) {
            passLetter[i] = rand() % 87 + 35;
        }
        passLetter[passLength] = 0;
        password.append(passLetter);
    }
    else
        password = "";
    return password;
}