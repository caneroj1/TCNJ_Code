//
//  Cryptography.cpp
//
//
//  Created by Joseph Canero on 11/17/12.
//
//

#include "Cryptography.h"
#include <cstddef>
#include <string>

//******************************************************************************************
Cryptography::Cryptography ()
{   //Constructor
    //Postcondition: a cryptography unit will be initialized with the a default encryptKey of b
    encryptKey = 'b';
}

//******************************************************************************************
Cryptography::Cryptography (char key)
{   //Parameterized constructor
    //Postcondition: a cryptography unit will be initialized with an ecryptKey of the lower case counterpart of the parameter key
    
    encryptKey = tolower(key);
}

//******************************************************************************************
string Cryptography::encryptPass (string toBeEncrypted)
{   //this will encrypt a single string
    //Postcondition: the string is encrypted with a bitwise XOR operation
    
    string encryptedString (toBeEncrypted);
    
    if (toBeEncrypted.empty()) //if the string passed in is empty, return it
        return toBeEncrypted;
    
    for (int i = 0; i < encryptedString.length(); i++) {  //loop through the parameter string and add each character to the
        cout << encryptedString[i] << endl;
        encryptedString[i] ^= encryptKey;            //char array and then encrypt
    }
    return encryptedString;
    
}

//******************************************************************************************
string Cryptography::decryptPass (string toBeDecrypted)
{   //this will decrypt a single string
    //Postcondition: the string is decrypted with a bitwise XOR operation
    
    string decryptedString (toBeDecrypted);
    
    if (toBeDecrypted.empty()) //if the string passed in is empty, return it
        return toBeDecrypted;
    
    for (int i = 0; i < decryptedString.length(); i++) { //loop through the parameter string and add each character to the            
        decryptedString[i] ^= encryptKey;                //char array and then decrypt
    }
    
    return decryptedString;
}

//******************************************************************************************
template <class T>
bool Cryptography::encryptAll (LinkedList<T>& list)
{   //encrypts the contents of the entire linked list
    //Postcondition: the contents of the linked list are encrypted and a bool is returned indicating success
    
    if (list.isEmpty()) {
        return true;
    }
    
    if (!list.isEmpty()) {
        LinkedList<string> encryptedList;
        Cryptography unit('v');
        string toBeEncrypted;
        
        while (!list.isEmpty()) {
            
            toBeEncrypted = (string)list.returnElement(0);
            list.removeElement(toBeEncrypted);
            
            string encryptedStr = unit.encryptPass(toBeEncrypted);
            encryptedList.insertElement(encryptedStr);
            toBeEncrypted = "";
        }
        
        cout << "THE ENCRYPTED LIST: " << encryptedList << endl;
        list = encryptedList;
        return true;
    }
    
        
}

//******************************************************************************************
template <class T>
bool Cryptography::decryptAll (LinkedList<T>& list)
{   //decrypts the contents of the entire linked list
    //Postcondition: the contents of the linked list are decrypted and a bool is returned indicating success
    
    if (list.isEmpty()) {
        return true;
    }
    
    if (!list.isEmpty()) {
        LinkedList<string> decryptedList;
        Cryptography unit('v');
        string toBeDecrypted;
        
        while (!list.isEmpty()) {
            toBeDecrypted = (string)list.returnElement(0);
            list.removeElement(toBeDecrypted);
            
            string decryptedStr = unit.decryptPass(toBeDecrypted);
            decryptedList.insertElement(decryptedStr);
        }
        list = decryptedList;
        return true;
    }
    
}