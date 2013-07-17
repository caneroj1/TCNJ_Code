//
//  Cryptography.h
//  CSC260/Dr. Pulimood
//  Collaborative Project
//  Created by Joseph Canero on 11/17/12.
//
//

/* ********************************************
 
    This is the header file for the Cryptography module. This module is responsible for the encrypting and decrypting user data in as secure and
    efficient a fashion as possible. The encryption and decryption functions themselves utilize the XOR operator, a bitwise operator.
    The XOR operator lends itself to easy reversibility as it only needs to be applied once more after encryption to succesfully decrypt.
    This header file also specifies functions that serve to encrypt and decrypt the contents of an entire linked list.
 
   ******************************************** */

#if !defined (CRYPTOGRAPHY_H)
#define CRYPTOGRAPHY_H
#include <iostream>
#include <string>
#include <sstream>
#include "List.h"
#include "Account.h"
#include "StandardAccount.h"
#include "DescribedAccount.h"
#include "SubscribedAccount.h"
using namespace std;

class Cryptography
{
private:
    char encryptKey; //the key that will be used in the encrytion and decryption processes
    
public:
    /* Default Constructor
     Postcondition: a Cyptography class object is instantiated
     Parameters: none
     */
    Cryptography();
    /*  Parameterized constructor
     Postcondition: a Cyptography class object is instantiated
     Parameters: a char
     */
    Cryptography(char);
    /* decryptPass
     Precondition: a string needs to be decrypted
     Postcondition: the string is decrypted
     Parameters: a string
     Returns a string 
     */
    string decryptPass (string);
    /* encryptPass
     Precondition: a string needs to be encrypted
     Postcondition: the string is encrypted
     Parameters: a string
     Returns a string
     */
    string encryptPass (string);
    /* decryptAll
     Precondition: a linked list needs to have its contents decrypted
     Postcondition: the linked list will be filled with decrypted data
     Parameters: a pointer to a linked list
     Returns a pointer to a linked list
     */
    LinkedList* decryptAll (LinkedList *);
    /* encryptAll
     Precondition: a linked list needs to have its contents encrypted
     Postcondition: the linked list will be filled with encrypted data
     Parameters: a pointer to a linked list
     Returns a pointer to a linked list
     */
    LinkedList* encryptAll (LinkedList *);
};

#endif /* defined(____Cryptography__) */
