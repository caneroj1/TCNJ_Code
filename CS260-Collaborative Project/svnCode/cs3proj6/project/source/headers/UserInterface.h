#include <iostream>
#include <cctype>
#include "UserProfile.h"
#if !defined (USERINTERFACE_H)
#define USERINTERFACE_H
using namespace std;

const int MaxAttempts = 10;

class UserInterface
{
	private:
		char answer;
		int attempts;
		UserProfile *profile;
		char getValidChar();
		
	public:
		UserInterface();	// Default constructor
		
		//----------------------------------------------------------
		// function: createProfileOrLogin
		// parameters: void
		// precondition: Start of the program and the user must decide either
		//				to create a new profile or login to existing one
		// postcondition: User's choice is determined and stored
		// return type: void
		//----------------------------------------------------------
		
		void createOrLog(void);
		
		
		//----------------------------------------------------------
		// function: loginScreen()
		// parameters: void
		// precondition: The User has decided to log in to existing account
		// postcondition: The user successfully logs into the system ready
		//				state OR lockout if the user fails to enter the
		//				correct password several times consecutively
		// return type: void
		//----------------------------------------------------------
		
		void loginScreen(void);
		
		
		//----------------------------------------------------------
		// function: createNewProfile()
		// paramters: none
		// precondition: A new user decided to create a new profile
		// postcondition: A new profile with an empty list is instantiated.
		//				The user enters UN and PW, which is stored, and
		//				the system enters the ready state
		// return type: void
		//----------------------------------------------------------
		
		void createNewProfile(void);
		
		
		//----------------------------------------------------------
		// function: mainMenu()
		// parameters: none
		// precondition: The system enters the ready state. The function
		//			presents operation options to the user. Based on user
		//			selection, the function calls profile functions
		// postcondition: Loops until the user breaks the loop.
		// return type: void
		//----------------------------------------------------------
		
		void mainMenu(void);
		
		
		//----------------------------------------------------------
		// function: exitProgram()
		// parameters: none
		// precondition: The user opted to break the mainMenu loop
		// postcondition: The data is encrypted, written to text file.
		//				The program releases all dynamic memory back to OS
		// return type: void
		//----------------------------------------------------------
		
		void exitProgram(void);
};

#endif
