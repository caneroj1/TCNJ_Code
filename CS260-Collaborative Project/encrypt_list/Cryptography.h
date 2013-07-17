//
//  Cryptography.h
//  
//
//  Created by Joseph Canero on 11/17/12.
//
//

#ifndef ____Cryptography__
#define ____Cryptography__

#include <iostream>
#include <string>
#include "List.h"
#include "List.cpp"

using namespace std;

class Cryptography
{
private:
    char encryptKey;
    
public:
    Cryptography();
    Cryptography(char);
    string decryptPass (string);
    string encryptPass (string);
    template <class T>
    bool decryptAll (LinkedList<T>&);
    template <class T>
    bool encryptAll (LinkedList<T>&);
};

#endif /* defined(____Cryptography__) */
