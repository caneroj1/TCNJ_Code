#include "../headers/UserProfile.h"
using namespace std;

UserProfile::UserProfile(string user)
{
	accounts = new LinkedList();
	username = user;
	reader = new Reader(username);
	writer = new Writer(username);
}

UserProfile::UserProfile(const UserProfile& prof)
{
	accounts = new LinkedList(*prof.accounts);
	username = prof.username;
	reader = new Reader(username);
	writer = new Writer(username);
}

UserProfile::~UserProfile()
{
	delete accounts;
	delete reader;
	delete writer;
}

UserProfile& UserProfile::operator= (const UserProfile& prof)
{
	if (this==&prof) return *this;
	else
	{
		username = prof.username;
		delete accounts;
		delete reader;
		delete writer;
		accounts = new LinkedList(*prof.accounts);
		reader = new Reader(username);
		writer = new Writer(username);
		return *this;
	}
}

bool UserProfile::createFile()
{
	bool success = writer->openFile();
	if (success)
	{
		string tempPass = crypt.encryptPass(password);
		writer->writeAll(tempPass, accounts);
		writer->closeFile();
	}
	return success;
}

bool UserProfile::openProfile()
{
	bool success = reader->openFile();
    if (success)
    {
        password = reader->readAll(accounts);   // Keep in mind return parameter
        password = crypt.decryptPass(password);
		reader->closeFile();
    }
	return success;
}

bool UserProfile::checkPass(string pass)
{
    if (password.compare(pass)==0)
    {
        accounts = crypt.decryptAll(accounts);
        return true;
    }
    else return false;
}

void UserProfile::addAccount()
{
	bool valid = false;
	char ans, genPW;
	string sName, sUserName, sPassword, sURL;
	string sDescrip, subExpiry, subMonthFee;
	Account* acct;
	
	cout << "\n**********************************************************" << endl;
	cout << "Enter which type of account you registered:" << endl;
	cout << "A -- STANDARD ACCOUNT" << endl;
	cout << "\t-Consists of a site name, username, password, and URL." << endl;
	cout << "D -- DESCRIBED STANDARD ACCOUNT" << endl;
	cout << "\t-Consists of the same attributes as standard AND a brief description." << endl;
	cout << "S -- SUBSCRIPTION TO A PAID SERVICE" << endl;
	cout << "\t-Consists of all above attributes AND an expiration date and monthly cost." << endl;
	cout << "**********************************************************" << endl;
	do
	{
		cout << "\nSelection:  ";
		ans = getValidChar();
		ans = toupper(ans);
		if (ans!='A' && ans!='D' && ans!='S')
		{
			cout << "***Invalid Input***" << endl;
			valid = false;
		} else valid = true;
	} while (!valid);
	
	// Obtain user input for site name and username
	cout << "\nNow you must enter all the attributes of your new account individually." << endl;
	cout << "Please enter the name of the site you registered the account." << endl;
	getline(cin, sName);
	cout << "\nPlease enter your username for " << sName << endl;
	getline(cin, sUserName);
	
	sPassword = makePass();
	
	// Obtain the URL
	cout << "\nPlease enter the home URL of " << sName << endl;
	getline(cin, sURL);
	
	// Operate on the user's Account type selection
	switch (ans)
	{
		case 'A':
			acct = new StandardAccount(StanAcctAttr, sName, sUserName, sPassword, sURL);
			break;
		case 'D':
			cout << "\nPlease enter a brief, single-line description of " << sName << endl;
			getline(cin, sDescrip);
			acct = new DescribedAccount(DescAcctAttr, sName, sUserName, sPassword, sURL, sDescrip);
			break;
		case 'S':
			cout << "\nPlease enter a brief, single-line description of " << sName << endl;
			getline(cin, sDescrip);
			cout << "\nPlease enter the expiration date of the subscription to " << sName << endl;
			getline(cin, subExpiry);
			cout << "\nPlease enter the monthly fee of the subscription to " << subMonthFee << endl << "$ ";
			getline(cin, subMonthFee);
			acct = new SubscribedAccount(SubAcctAttr, sName, sUserName, sPassword,
							sURL, sDescrip, subExpiry, subMonthFee);
			break;
	}
	// Finally insert the new element into the list
	accounts->insertElement(acct);
}

void UserProfile::printAll()
{
	accounts->displayElements();
}

bool UserProfile::searchAccounts()
{
	string field;
	Account *target, *found;
	cout << "\nEnter the name of the site of the account for which you would like to search." << endl;
	getline(cin, field);
	target = new StandardAccount(field);
	found = accounts->search(target);
	delete target;
	target = NULL;
	
	if (found==NULL) return false;
	else
	{
		cout << "\nThe system has found the target you searched for:" << endl << endl;
		found->printToScreen();
		cout << "\n\n************************************************" << endl;
		cout << "What would you like to do with this account?" << endl;
		cout << "M - MODIFY THE ACCOUNT DATA" << endl;
		cout << "P - PRINT THE DATA AGAIN" << endl;
		cout << "R - REMOVE ACCOUNT" << endl;
		cout << "************************************************" << endl;
		char ans;
		bool valid = false;
		do
		{
			cout << "Selection:  ";
			ans = getValidChar();
			ans = toupper(ans);
			if (ans!='M' && ans!='P' && ans!='R')
			{
				valid = false;
				cout << "***INVALID INPUT! Try again.***" << endl;
			} else valid = true;
		} while (!valid);
		
		switch (ans)
		{
			case 'M':
				modifyAccount(found);
				break;
			case 'P':
				cout << endl;
				found->printToScreen();
				cout << endl;
				break;
			case 'R':
				valid = accounts->removeElement(found);
				if (valid) cout << "\nAccount removed successfully." << endl;
				else cout << "\nAn error occurred trying to remove the account. Please try again." << endl;
				break;
		}
		return true;
	}
}

void UserProfile::removeAccount()
{
	bool success = false;
	do
	{
		string field;
		cout << "\nPlease enter the name of the site for the account you want to remove." << endl;
		getline(cin, field);
		Account *found, *rem;
		rem = new StandardAccount(field);
		
		if (accounts->listContains(rem))
        {
			found = accounts->search(rem);
            cout << "\nNyan security has found the account you searched for:" << endl;
			found->printToScreen();
			cout << "\nAre you sure you'd like to remove it (Y/N)?" << endl;
            char ans = getValidChar();
            ans = toupper(ans);
            if (ans=='Y') success = accounts->removeElement(found);
			if (!success) cout << "Error removing account from list. Try again." << endl;
			else cout << "\nThe operation completed successfully." << endl;
			found = NULL;
        }
		else
		{
			cout << "\nAccount not found in the list. Would you like to " <<
				"return to the main menu or search again? (R/S)?" << endl;
            char ans;
            do {
                ans = getValidChar();
                ans = toupper(ans);
            } while (ans!='R' && ans!='S');
			if (ans=='R') success = true;
			else if (ans=='S') success = false;
		}
		
		delete rem;
	} while (!success);
}

bool UserProfile::writeData()
{
	string tempPass = crypt.encryptPass(password);
	accounts = crypt.encryptAll(accounts);
	bool success = writer->openFile();
	if (success)
	{
		cout << "Writing data to file......" << endl;
		writer->writeAll(tempPass, accounts);
		writer->closeFile();
	}
	else cout << "***ERROR***" << endl;
	return success;
}

void UserProfile::modifyAccount(Account* acct)
{
	bool valid = false;
	char ans = 'A';
	string change;
	int numAtt = acct->getNumAttributes();
	
	do
	{
		cout << "\n*******************************************************" << endl;
		cout << "Which attribute would you like to rewrite?" << endl;
		cout << "N - SITE NAME" << endl << "U - USERNAME" << endl;
		cout << "P - PASSWORD" << endl << "Z - URL" << endl;
		if (numAtt != StanAcctAttr) cout << "D - DESCRIPTION" << endl;
		if (numAtt == SubAcctAttr)
			cout << "E - SUBSCRIPTION EXPIRATION" << endl << "M - MONTHLY FEE" << endl;
		cout << "*******************************************************" << endl;
		
		do
		{
			cout << "Selection:  ";
			ans = getValidChar();
			ans = toupper(ans);
			if (ans!='N' && ans!='U' && ans!='P' && ans!='Z') valid = false;
			else valid = true;
			if (!valid)
			{
				if (numAtt==DescAcctAttr)
				{
					if (ans!='D') valid = false;
					else valid = true;
				} else if (numAtt==SubAcctAttr)
				{
					if (ans!='D' && ans!='E' && ans!='M') valid = false;
					else valid = true;
				}
			}
			if (!valid) cout << "***INVALID INPUT! Try again.***" << endl;
		} while (!valid);
		
		cout << "\n\nCurrent account data:" << endl;
		acct->printToScreen();
		cout << endl;
		
		switch (ans)
		{
			case 'N':
				cout << "\nThe site name is: " << acct->getSiteName() << endl;
				cout << "Please enter your new desired site name." << endl;
				getline(cin, change);
				acct->setSiteName(change);
				break;
			case 'U':
				cout << "\nThe current username is: " << acct->getUserName() << endl;
				cout << "Please enter your new username. " << endl;
				getline(cin, change);
				acct->setUserName(change);
				break;
			case 'P':
				cout << "\nThe current password is: " << acct->getSitePassword() << endl;
				change = makePass();
				acct->setSitePassword(change);
				break;
			case 'Z':
				cout << "\nThe current site URL is: " << acct->getSiteURL() << endl;
				cout << "Please enter the new URL." << endl;
				getline(cin, change);
				acct->setSiteURL(change);
				break;
			case 'D':
				cout << "\nThe current site description is: " << endl << acct->getSiteDescription() << endl;
				cout << "Please enter the new description." << endl;
				getline(cin, change);
				acct->setSiteDescription(change);
				break;
			case 'E':
				cout << "\nThe current expiry date of the subscription is: " << acct->getSubExpiration() << endl;
				cout << "Please enter the updated expiry date: " << endl;
				getline(cin, change);
				acct->setSubExpiration(change);
				break;
			case 'M':
				cout << "The subscription's current monthly fee is: $" << acct->getMonthlyFee() << endl;
				cout << "Please enter the new monthly fee." << endl;
				getline(cin, change);
				acct->setMonthlyFee(change);
				break;
		}
		
		cout << "Would you like to modify another field (Y/N)?" << endl;
		ans = getValidChar();
		ans = toupper(ans);
	} while (ans=='Y');
}

void UserProfile::setPassword(string pass)
{
	password = pass;
}

char UserProfile::getValidChar() const
{
	bool valid = false;
	char in;
	do
	{
		cin >> in;
		if (cin.fail())
		{
			cin.clear();
			valid = false;
			cout << "***INVALID INPUT! Try again.***" << endl;
		} else valid = true;
		cin.ignore(80,'\n');
	} while (!valid);
	return in;
}

int UserProfile::getValidInt() const
{
	bool valid = false;
	int in;
	do
	{
		cin >> in;
		if (cin.fail() || in<10 || in>64)
		{
			cin.clear();
			valid = false;
			cout << "***INVALID INPUT! Try again.***" << endl;
		} else valid = true;
		cin.ignore(80,'\n');
	} while (!valid);
	return in;
}

string UserProfile::makePass() const
{
	char genPW;
	string pass;
	cout << "\nWould you like the system to generate a random password?" << endl;
	cout << "Enter Y for yes, or N to enter your own password." << endl;
	cout << "Selection:  ";
	genPW = getValidChar();
	genPW = toupper(genPW);
	if (genPW=='Y')
	{
		cout << "\nHow many characters long would you like this password? (min 10, max 64)" << endl;
		int chars = getValidInt(); 
		Generator generate;
		pass = generate.generatePass(chars);
		cout << "\nYOUR NEW PASSWORD IS:\n" << pass << endl;
	} else
	{
		cout << "\nPlease enter your new password." << endl;
		getline(cin, pass);
	}
	return pass;
}
