#if !defined (ACCOUNT_H)
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account{
	protected:
		int numAttributes;
		string siteName;
		string sitePassword;
		string userName;
		string siteURL;
	public:
		Account(); //Default constructor
		Account(int); //Parameterized constructor for number of elements
		Account(string); //Parameterized constructor for account name
		Account(int, string, string, string, string);//Parameterized constructor for each possible user input
    //----------------------------------------------------------
    // function: getNumAttributes()
    // parameters: void
    // precondition: an account has been created and numAtrributes has been initialized.
    // postcondition: the int numAttributes has been returned to the calling class.
    // return type: int (number of elements in the account)
    //----------------------------------------------------------
		int getNumAttributes()const;
    //----------------------------------------------------------
    // function: getUserName()
    // parameters: void
    // precondition: an account has been created and userName has been initialized.
    // postcondition: the string userName has been returned to the calling class.
    // return type: string (user name for the account)
    //----------------------------------------------------------
		string getUserName()const;
    //----------------------------------------------------------
    // function: getSitePassword()
    // parameters: void
    // precondition: an account has been created and sitePassword has been initialized.
    // postcondition: the string sitePassword has been returned to the calling class.
    // return type: string (password for the account)
    //----------------------------------------------------------
		string getSitePassword()const;
    //----------------------------------------------------------
    // function: getSiteName()
    // parameters: void
    // precondition: an account has been created and siteName has been initialized.
    // postcondition: the string siteName has been returned to the calling class.
    // return type: string (the name of the website)
    //----------------------------------------------------------
		string getSiteName()const;
    //----------------------------------------------------------
    // function: getSiteURL()
    // parameters: void
    // precondition: an account has been created and siteURL has been initialized.
    // postcondition: the string siteURL has been returned to the calling class.
    // return type: string (URL of the account website)
    //----------------------------------------------------------
		string getSiteURL()const;
    //----------------------------------------------------------
    // function: getSiteDesciption()
    // parameters: void
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: string (a short description of the website or account)
    //----------------------------------------------------------
		virtual string getSiteDescription()const = 0;
    //----------------------------------------------------------
    // function: getSubExpiration()
    // parameters: void
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: string (the expiration date of the subscription)
    //----------------------------------------------------------
		virtual string getSubExpiration()const = 0;
    //----------------------------------------------------------
    // function: getMonthlyFee()
    // parameters: void
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: string (the per monthly cost of the subscription)
    //----------------------------------------------------------
		virtual string getMonthlyFee()const = 0;
    //----------------------------------------------------------
    // function: setNumAttributes()
    // parameters: int (the number of attributes for the Account)
    // precondition: An account object has been instantiated and numAttributes has been initialized.
    // postcondition: The int parameter has been stored in the data field numAttributes
    // return type: void
    //----------------------------------------------------------
		void setNumAttributes(int);
    //----------------------------------------------------------
    // function: setUserName()
    // parameters: string (the user name for the Account)
    // precondition: An account object has been instantiated and userName has been initialized.
    // postcondition: The string parameter has been stored in the data field userName.
    // return type: void
    //----------------------------------------------------------
		void setUserName(string);
    //----------------------------------------------------------
    // function: setSitePassword()
    // parameters: string (the password for the Account)
    // precondition: An account object has been instantiated and password has been initialized.
    // postcondition: The string parameter has been stored in the data field sitePassword.
    // return type: void
    //----------------------------------------------------------
		void setSitePassword(string);
    //----------------------------------------------------------
    // function: setSiteName()
    // parameters: string (the website name)
    // precondition: An account object has been instantiated and siteName has been initialized.
    // postcondition: The string parameter has been stored in the data field siteName.
    // return type: void
    //----------------------------------------------------------
		void setSiteName(string);
    //----------------------------------------------------------
    // function: setSiteURL()
    // parameters: string (the URL for the website pertaining to the Account)
    // precondition: An account object has been instantiated and siteURL has been initialized.
    // postcondition: The string parameter has been stored in the data field siteURL.
    // return type: void
    //----------------------------------------------------------
		void setSiteURL(string);
    //----------------------------------------------------------
    // function: setSiteDescription()
    // parameters: string (a short description of the account)
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: void
    //----------------------------------------------------------
		virtual void setSiteDescription(string) = 0;
    //----------------------------------------------------------
    // function: setSubExpiration()
    // parameters: string (the expiration date of the subscription)
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: void
    //----------------------------------------------------------
		virtual void setSubExpiration(string) = 0;
    //----------------------------------------------------------
    // function: setMonthlyFee()
    // parameters: string (the cost of the subscription per month)
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: void
    //----------------------------------------------------------
		virtual void setMonthlyFee(string) = 0;
    //----------------------------------------------------------
    // function: operator>()
    // parameters: Account* (a pointer to an object that derives from the abstract base class Account)
    // precondition: Two objects that derive from the Account class have been provided to the function, one the caller, the other a parameter.
    // postcondition: A boolean is returned indicating which object is greater than the other based on the ACII value of the account name. This operation is not case sensitive.
    // return type: bool (true if the calling object is > the parameter)
    //----------------------------------------------------------
		bool operator>(const Account*);
    //----------------------------------------------------------
    // function: operator<()
    // parameters: Account* (a pointer to an object that derives from the abstract base class Account)
    // precondition: Two objects that derive from the Account class have been provided to the function, one the caller, the other a parameter.
    // postcondition: A boolean is returned indicating which object is less than the other based on the ACII value of the account name. This operation is not case sensitive.
    // return type: bool (true if the calling object is < the parameter)
    //----------------------------------------------------------
		bool operator<(const Account*);
    //----------------------------------------------------------
    // function: operator==()
    // parameters: Account* (a pointer to an object that derives from the abstract base class Account)
    // precondition: Two objects that derive from the Account class have been provided to the function, one the caller, the other a parameter.
    // postcondition: A boolean is returned indicating if the objects are equal based on the ACII value of the account name. This operation is not case sensitive.
    // return type: bool (true if the calling object is == the parameter)
    //----------------------------------------------------------
		bool operator==(const Account*);
    //----------------------------------------------------------
    // function: printToFile()
    // parameters: ostream& (a reference to an ostream object used to output the data fields of the Account object)
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: ostream& (the reference to the parameter originally supplied)
    //----------------------------------------------------------
		virtual ostream& printToFile(ostream&) = 0;
    //----------------------------------------------------------
    // function: printToScreen()
    // parameters: void
    // precondition: the derived classes of Account have implemented their own version of this method if applicable.
    // postcondition: the correct method that has been redefined in the derived class has been called.
    // return type: void
    //----------------------------------------------------------
		virtual void printToScreen(void) const = 0;
};		

#endif
