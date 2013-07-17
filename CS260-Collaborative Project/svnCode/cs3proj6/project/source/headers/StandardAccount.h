#if !defined (STANDARDACCOUNT_H)
#define STANDARDACCOUNT_H
#include <iostream>
#include "Account.h"

class StandardAccount : public Account{

	public:
		StandardAccount(); //Default constructor
		StandardAccount(int); //Parameterized constructor for number of elements
		StandardAccount(string); //Parameterized constructor for account name
		StandardAccount(int, string, string, string, string); //Parameterized constructor for each possible user input
    //----------------------------------------------------------
    // function: getSiteDescription()
    // parameters: void
    // precondition: This method is never called by the program.It is simply here to facilitate the virtual function of the base class.
    // postcondition: Returns an error message.
    // return type: string (Error message)
    //----------------------------------------------------------
		string getSiteDescription()const;
    //----------------------------------------------------------
    // function: getSubExpiration()
    // parameters: void
    // precondition: This method is never called by the program.It is simply here to facilitate the virtual function of the base class.
    // postcondition: Returns an error message.
    // return type: string (Error message)
    //----------------------------------------------------------
		string getSubExpiration()const;
    //----------------------------------------------------------
    // function: getMonthlyFee()
    // parameters: void
    // precondition: This method is never called by the program.It is simply here to facilitate the virtual function of the base class.
    // postcondition: Returns an error message.
    // return type: string (Error message)
    //----------------------------------------------------------
		string getMonthlyFee()const;
    //----------------------------------------------------------
    // function: setSiteDescription()
    // parameters: string
    // precondition: This method is never called by the program.It is simply here to facilitate the virtual function of the base class.
    // postcondition: Nothing happens.
    // return type: void
    //----------------------------------------------------------
		void setSiteDescription(string);
    //----------------------------------------------------------
    // function: setSubExpiration()
    // parameters: string
    // precondition: This method is never called by the program.It is simply here to facilitate the virtual function of the base class.
    // postcondition: Nothing happens.
    // return type: void
    //----------------------------------------------------------
		void setSubExpiration(string);
    //----------------------------------------------------------
    // function: setMonthlyFee()
    // parameters: string
    // precondition: This method is never called by the program.It is simply here to facilitate the virtual function of the base class.
    // postcondition: Nothing happens.
    // return type: void
    //----------------------------------------------------------
		void setMonthlyFee(string);
    //----------------------------------------------------------
    // function: printToFile()
    // parameters: ostream& (a reference to an ostream object used to output the data fields of the Account object)
    // precondition: A file has been opened in which to write to and the calling function has passed a valid ostream object in which to utilize.
    // postcondition: All the data fields have been printed to the ostream object and the ostream object has been returned to the calling function.
    // return type: ostream& (the reference to the parameter originally supplied)
    //----------------------------------------------------------
		ostream& printToFile(ostream&);
    //----------------------------------------------------------
    // function: printToScreen()
    // parameters: void
    // precondition: All the data fields have been initialized.
    // postcondition: All the data fields have been labeled and printed to the primary output device.
    // return type: void
    //----------------------------------------------------------
		void printToScreen() const;
};

#endif
