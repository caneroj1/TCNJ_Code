#if !defined (USERPROFILE_H)
#define USERPROFILE_H
#include <iostream>
#include "Reader.h"
#include "Account.h"
#include "StandardAccount.h"
#include "DescribedAccount.h"
#include "SubscribedAccount.h"
#include "Cryptography.h"
#include "Writer.h"
#include "List.h"
#include "Generator.h"
using namespace std;

const int StanAcctAttr=4, DescAcctAttr=5, SubAcctAttr=7;

class UserProfile
{
	private:
		LinkedList *accounts;
		string username, password;
		Cryptography crypt;
		Reader *reader;
		Writer *writer;
		char getValidChar() const;
		int getValidInt() const;
		
	public:
		UserProfile(string);	// Default constructor
		UserProfile(const UserProfile&);	// Copy constructor
		~UserProfile();			// Destructor
		UserProfile& operator= (const UserProfile&);	// Assignment operator
		
		
		//----------------------------------------------------------
		// function: createFile()
		// parameters: none
		// precondition: New user has decided to create a new profile
		// postcondition: New file created associated with new profile
		// return type: bool (success or failure of operation)
		//----------------------------------------------------------
		
		bool createFile(void);
		
		
		//----------------------------------------------------------
		// function: openProfile()
		// parameters: none
		// precondition: The user has decided to log in to existing profile
		// postcondition: If the username and password entered by the user
		//			in UI is correct, system enters ready state, with 
		//			all encrypted data on file stored and decrypted.
		// return type: bool (success or failure of operation)
		//----------------------------------------------------------
		
		bool openProfile(void);
		
		
		//----------------------------------------------------------
		// function: checkPass()
		// parameter: string password
		// precondition: During login attempt, user enters password and
		//			all encrpyted data is stored in memory
		// postcondition: Function compares the user entered PW to the 
		//			decrypted PW from the file. If they match, the system
		//			will (outside this func) decrypt all data in memory
		// return type: bool (result of PW comparison)
		//----------------------------------------------------------
		
		bool checkPass(string);
		
		
		//----------------------------------------------------------
		// function: writeData()
		// parameters: none
		// precondition: User has decided to exit the program, so now
		//			the system must save all changes to file
		// postcondition: All user data in memory is encrypted and
		//			printed to the output file.
		// return type: bool (success or failure of operation)
		//----------------------------------------------------------
		
		bool writeData(void);
		
		
		//----------------------------------------------------------
		// function: addAccount()
		// parameters: none
		// precondition: The user has decided to add a new account record
		// postcondition: Function accepts all fields for account data from
		//			user input. The new account is added to LinkedList
		// return type: void
		//----------------------------------------------------------
		
		void addAccount(void);
		
		
		//----------------------------------------------------------
		// function: removeAccount()
		// parameters: none
		// precondition: The user decided to remove an account record
		// postcondition: Function accepts the siteName from user input of
		//			desired account. If found, account is removed from list
		// return type: void
		//----------------------------------------------------------
		
		void removeAccount(void);
		
		
		//----------------------------------------------------------
		// function: printAll()
		// parameters: none
		// precondition: User decided to print all accounts to screen
		// postcondition: All accounts printed to screen
		// return type: void
		//----------------------------------------------------------
		
		void printAll(void);
		
		
		//----------------------------------------------------------
		// function: searchAccounts()
		// parameters: none
		// preconditions: User decided to search for a specific account
		// postcondition: Loops until desired account is found or user
		//			decides to exit. If found, presents operation options
		//			to user and completes that operation.
		// return type: bool (success or failure of operation)
		//----------------------------------------------------------
		
		bool searchAccounts(void);
		
		
		//----------------------------------------------------------
		// function: setPassword()
		// parameters: string password
		// precondition: need to set the instance data
		// postcondition: instance data rewritten/reassigned
		// return type: void
		//----------------------------------------------------------
		
		void setPassword(string);
		
		
		//----------------------------------------------------------
		// function: modifyAccount()
		// parameters: Account *acct (account to be modified)
		// precondition: In searchAccount(), user found desired search
		//			target and decided to modify the data
		// postcondition: User determines which field to edit and enters
		//			the new change. Loops until user is done with changes
		// return type: void
		//----------------------------------------------------------
		
		void modifyAccount(Account*);
		
		
		//----------------------------------------------------------
		// function: makePass()
		// parameters: none
		// precondition: User must enter a password for an account.
		// postcondition: Allows the user either to enter own password,
		//			or have the system generate a random one
		// return type: string (the new password)
		//----------------------------------------------------------
		
		string makePass(void) const;
};

#endif
