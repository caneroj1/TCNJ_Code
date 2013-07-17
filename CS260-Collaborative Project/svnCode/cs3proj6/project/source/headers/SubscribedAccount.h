#if !defined (SUBSCRIBEDACCOUNT_H)
#define SUBSCRIBEDACCOUNT_H
#include <iostream>
#include "Account.h"

class SubscribedAccount : public Account{

	private:
		string siteDescription;
		string subExpiration;
		string monthlyFee;
	public:
		SubscribedAccount(); //Default constructor
		SubscribedAccount(int); //Parameterized constructor for number of elements
		SubscribedAccount(string); //Parameterized constructor for account name
		SubscribedAccount(int, string, string, string, string, string, string, string); //Parameterized constructor for each possible user input including the site description, subscription expiration data and monthly
    
    //----------------------------------------------------------
    // function: getSiteDescription()
    // parameters: void
    // precondition: An object of type SubscribedAccount has been created and  siteDescription has been initialized.
    // postcondition: The string containing the description of the site has been returned.
    // return type: string (short description of the Account)
    //----------------------------------------------------------
		string getSiteDescription()const;
    //----------------------------------------------------------
    // function: getSubExpiration()
    // parameters: void
    // precondition: An object of type SubscribedAccount has been created and siteExpiration has been initialized.
    // postcondition: The string containing the expiration date has been returned.
    // return type: string (the expiration date of the subscription)
    //----------------------------------------------------------
		string getSubExpiration()const;
    //----------------------------------------------------------
    // function: getMonthlyFee()
    // parameters: void
    // precondition: An object of type SubscribedAccount has been created and monthlyFee has been initialized.
    // postcondition: The string containing the monthly fee has been returned.
    // return type: string (the cost per month of the subscription)
    //----------------------------------------------------------
		string getMonthlyFee()const;
    //----------------------------------------------------------
    // function: setSiteDescription()
    // parameters: string (a short description of the site)
    // precondition: An object of type SubscribedAccount has been created and siteDescrpition has been initialized.
    // postcondition: siteDescrption has been set to the value of the parameter.
    // return type: void
    //----------------------------------------------------------
		void setSiteDescription(string);
    //----------------------------------------------------------
    // function: setSubExpiration()
    // parameters: string (the expiration date of the subscription)
    // precondition: An object of type SubscribedAccount has been created and subExpiration has been initialized.
    // postcondition: subExpiration has been set to the value of the parameter.
    // return type: void
    //----------------------------------------------------------
		void setSubExpiration(string);
    //----------------------------------------------------------
    // function: setMonthlyFee()
    // parameters: string (the monthly cost of the subscription)
    // precondition: An object of type SubscribedAccount has been created and monthlyFee has been initialized.
    // postcondition: monthlyFee has been set to the value of the parameter.
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
