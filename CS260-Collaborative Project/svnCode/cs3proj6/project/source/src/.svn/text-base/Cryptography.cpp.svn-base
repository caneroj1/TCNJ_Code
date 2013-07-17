//
//  Cryptography.cpp
//  CSC260/Dr. Pulimood
//  Collaborative Project
//  Created by Joseph Canero on 11/17/12.
//
//

/* ********************************************
 
 This is the implementation file for the Cryptography module. This module is responsible for defining the methods specified in the header file
 
 ******************************************** */

#include "../headers/Cryptography.h"

//******************************************************************************************
Cryptography::Cryptography ()
{   //Constructor
    //Postcondition: a cryptography unit will be initialized with the a default encryptKey of b
    encryptKey = 'v';
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
    ostringstream oss;
    string encryptedString;
    
    if (toBeEncrypted.empty()) //if the string passed in is empty, return it
        return toBeEncrypted;
    
    for (int i = 0; i < toBeEncrypted.length(); i++) {  //loop through the parameter string and add each character to the
        char enc = toBeEncrypted[i] ^ encryptKey;                 //char array and then encrypt
        oss << enc;
    }
    
    encryptedString = oss.str();
    return encryptedString;
    
}

//******************************************************************************************
string Cryptography::decryptPass (string toBeDecrypted)
{   //this will decrypt a single string
    //Postcondition: the string is decrypted with a bitwise XOR operation
    ostringstream oss;
    string decryptedString;
    
    if (toBeDecrypted.empty()) //if the string passed in is empty, return it
        return toBeDecrypted;
    
    for (int i = 0; i < toBeDecrypted.length(); i++) { //loop through the parameter string and add each character to the
        char enc = toBeDecrypted[i] ^ encryptKey;                //char array and then decrypt
        oss << enc;
    }
    decryptedString = oss.str();
    return decryptedString;
}

//******************************************************************************************
//template<class T>
LinkedList* Cryptography::encryptAll (LinkedList* list)
{   //encrypts the contents of the entire linked list
    //Postcondition: the contents of the linked list are encrypted and a linked list is returned
    
    
	LinkedList* encList = new LinkedList();
	if(list->isEmpty()) delete list;
	else
	{
		int elems = list->sizeOfList();
		for (int i=0; i<elems; i++)
		{
			string sName, username, pass, url, descrip, subexp, mofee;
			Account *encrypted, *acct = list->returnElement(i);
			int numAttr = acct->getNumAttributes();
			sName = encryptPass(acct->getSiteName());
			username = encryptPass(acct->getUserName());
			pass = encryptPass(acct->getSitePassword());
			url = encryptPass(acct->getSiteURL());
			
			switch (numAttr)
			{
				default:
					encrypted = new StandardAccount(numAttr, sName, username, pass, url);
					break;
				case 5:
					descrip = encryptPass(acct->getSiteDescription());
					encrypted = new DescribedAccount(numAttr, sName, username, pass, url, descrip);
					break;
				case 7:
					descrip = encryptPass(acct->getSiteDescription());
					subexp = encryptPass(acct->getSubExpiration());
					mofee = encryptPass(acct->getMonthlyFee());
					encrypted = new SubscribedAccount(numAttr, sName, username, pass, url, descrip, subexp, mofee);
					break;
				
			}
			encList->insertElement(encrypted);
		}
		delete list;
	}
	return encList;
}

//******************************************************************************************
//template<class T>
LinkedList* Cryptography::decryptAll (LinkedList* list)
{   //decrypts the contents of the entire linked list
    //Postcondition: the contents of the linked list are decrypted and a linked list is returned
    
    LinkedList* decList = new LinkedList();
	if(list->isEmpty()) delete list;
	else
	{
		int elems = list->sizeOfList();
		for (int i=0; i<elems; i++)
		{
			string sName, username, pass, url, descrip, subexp, mofee;
			Account *decrypted, *acct = list->returnElement(i);
			int numAttr = acct->getNumAttributes();
			sName = decryptPass(acct->getSiteName());
			username = decryptPass(acct->getUserName());
			pass = decryptPass(acct->getSitePassword());
			url = decryptPass(acct->getSiteURL());
			
			switch (numAttr)
			{
				default:
					decrypted = new StandardAccount(numAttr, sName, username, pass, url);
					break;
				case 5:
					descrip = decryptPass(acct->getSiteDescription());
					decrypted = new DescribedAccount(numAttr, sName, username, pass, url, descrip);
					break;
				case 7:
					descrip = decryptPass(acct->getSiteDescription());
					subexp = decryptPass(acct->getSubExpiration());
					mofee = decryptPass(acct->getMonthlyFee());
					decrypted = new SubscribedAccount(numAttr, sName, username, pass, url, descrip, subexp, mofee);
					break;
				
			}
			decList->insertElement(decrypted);
		}
		delete list;
	}
	return decList;
    
}
