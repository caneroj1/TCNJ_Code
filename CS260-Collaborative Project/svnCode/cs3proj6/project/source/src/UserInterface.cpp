#include "../headers/UserInterface.h"
using namespace std;

UserInterface::UserInterface()
{
	attempts = 0;
	answer = 'z';
	profile = NULL;
}

void UserInterface::createOrLog()
{
	bool complete = false;
	cout << "WELCOME TO NYAN SECURITY'S PASSWORD MANAGER!" << endl;
	cout << "\nAt each menu screen, enter the character that represents";
	cout << " menu item you would like to select." << endl;
	
	do
	{
		cout << "\n\nAre you a new user or an existing user?" << endl;
		cout << "**********************************" << endl;
		cout << "L - LOGIN" << endl;
		cout << "C - CREATE NEW PROFILE" << endl;
		cout << "**********************************" << endl;
		answer = getValidChar();
		answer = toupper(answer);
		
		if (answer!='L' && answer!='C')
		{
			complete = false;
			cout << "***INVALID INPUT! Try again.***" << endl;
		} else complete = true;
	} while (!complete);
	
	if (answer=='L') loginScreen();
	else if (answer=='C') createNewProfile();
}

void UserInterface::loginScreen()
{
	bool success = false;
	string username, password;
	cout << "\n\nYou have opted to login to an existing profile." << endl;
	
	do
	{
		cout << "\nPlease enter your profile username." << endl;
		getline(cin, username);
		profile = new UserProfile(username);
		success = profile->openProfile();
		if (!success)
        {
            cout << "***INVALID INPUT! Try again.***" << endl;
            delete profile;
            profile = NULL;
        }
	} while (!success);
	
	success = false;
	do
	{
		cout << "\nPlease enter your profile password." << endl;
		getline(cin, password);
		success = profile->checkPass(password);
		if (!success)
		{
			cout << "INCORRECT PASSWORD! Try again." << endl;
			attempts++;
		}
	} while (!success && attempts<MaxAttempts);
	
	if (attempts < MaxAttempts) mainMenu();
	else
	{
		cout << "\nYou have reached the maximum number of login attempts." << endl;
		cout << "So, because of your incompetence, BAILING OUT!" << endl;
		delete profile;
	}
}

void UserInterface::createNewProfile()
{
	bool success = false;
	string username, password;
	cout << "\n\nYou have opted to create a new user profile." << endl;
	
	do
	{
		cout << "\nPlease enter your desired username for your new profile." << endl;
		getline(cin, username);
		profile = new UserProfile(username);
		
		cout << "\nPlease enter your desired master password for your account." << endl;
		password = profile->makePass();
		profile->setPassword(password);
		success = profile->createFile();
		
		if (!success)
		{
			cout << "Invalid new username and/or password! Try again." << endl;
			delete profile;
			profile = NULL;
		}
	} while (!success);
	cout << "\n\nNyan Security is now logged into the system ready state." << endl;
	mainMenu();
}

void UserInterface::mainMenu()
{
	do
	{
		cout << "\n************************************************" << endl;
		cout << "\t\tMAIN MENU" << endl;
		cout << "Enter the character that corresponds to " << endl
				<< "the functionality you would like to carry out." << endl;
		cout << "\nA - ADD AN ACCOUNT" << endl;
		cout << "P - PRINT ALL ACCOUNTS TO SCREEN" << endl;
		cout << "R - REMOVE AN ACCOUNT" << endl;
		cout << "S - SEARCH FOR AN ACCOUNT" << endl;
		cout << "E - SAVE CHANGES AND EXIT PROGRAM" << endl;
		cout << "************************************************" << endl;
		cout << "Selection:  ";
		
		bool success = false, exit = false;
		do
		{
			answer = getValidChar();
			answer = toupper(answer);
			if (answer!='A' && answer!='P' && answer!='R' && answer!='S' && answer!='E')
			{
				success = false;
				cout << "***INVALID INPUT! Try again.***" << endl;
			} else success = true;
		} while (!success);
		
		switch (answer)
		{
			case 'A':
				cout << "\nYou have opted to add a new account to the system." << endl;
				profile->addAccount();
				break;
			case 'P':
				cout << "\nYou have opted to print all your accounts to the screen." << endl;
				profile->printAll();
				break;
			case 'R':
				cout << "\nYou have opted to remove an account from the system." << endl;
				profile->removeAccount();
				break;
			case 'S':
				cout << "\nYou have opted to search for an existing account.";
				success = profile->searchAccounts();
				if (!success) cout << "\nThe search has failed to find the target object." << endl;
				break;
			case 'E':
				exit = true;
				break;
			default:
				cout << "***INPUT ERROR!***" << endl;
				break;
		}
		
		if (!exit)
		{
			cout << "\nWould you like to return to the main menu?" << endl;
			cout << "Enter R to return or E to exit." << endl;
			cout << "Selection:  ";
			do
			{
				answer = getValidChar();
				answer = toupper(answer);
				if (answer!='R' && answer!='E')
				{
					cout << "***INVALID INPUT! Try again.***" << endl;
					success = false;
				} else success = true;
			} while (!success);
		}
	} while (answer=='R');
	exitProgram();
}

void UserInterface::exitProgram()
{
	cout << "You have opted to exit the program. Saving changes." << endl;
	bool success = profile->writeData();
	if (success) cout << "Closing program..." << endl;
	else
	{
		cout << "The system encountered an error while rewriting the text file." <<
				"Therefore, it is returning to the main menu." << endl;
		mainMenu();
	}
	delete profile;
}

char UserInterface::getValidChar()
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
