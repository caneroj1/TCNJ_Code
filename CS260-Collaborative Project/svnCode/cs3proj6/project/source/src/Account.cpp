#include "../headers/Account.h"

Account::Account(){
	numAttributes = 4;
	siteName = "siteName";
	sitePassword = "sitePassword";
	userName = "userName";
	siteURL = "siteURL";
}

Account::Account(int numattributes){
	numAttributes = numattributes;
	siteName = "siteName";
	sitePassword = "sitePassword";
	userName = "userName";
	siteURL = "siteURL";
}

Account::Account(string sitename){
	numAttributes = 4;
	siteName = sitename;
	sitePassword = "sitePassword";
	userName = "userName";
	siteURL = "siteURL";
}

Account::Account(int numattributes, string sitename, string username, string sitepassword, string siteurl){
	numAttributes = numattributes;
	siteName = sitename;
	sitePassword = sitepassword;
	userName = username;
	siteURL = siteurl;
}

//getters
int Account::getNumAttributes()const{
	return numAttributes;
}

string Account::getUserName()const{
	return userName;
}

string Account::getSitePassword()const{
	return sitePassword;
}

string Account::getSiteName()const{
	return siteName;
}

string Account::getSiteURL()const{
	return siteURL;
}

//setters
void Account::setNumAttributes(int numattributes){
	numAttributes = numattributes;
}

void Account::setUserName(string username){
	userName = username;
}

void Account::setSitePassword(string sitepassword){
	sitePassword = sitepassword;
}

void Account::setSiteName(string sitename){
	siteName = sitename;
}

void Account::setSiteURL(string siteurl){
	siteURL = siteurl;
}

//overloaded operators
bool Account::operator>(const Account* rhs){
	//Make a duplicate string of rhs and lhs
	string lhsCopy = siteName;
	string rhsCopy = rhs->siteName;
	
	//Set the duplicate strings to lower case
	for (int i = 0; i < lhsCopy.length(); i++){
		char c = lhsCopy[i];
		c = tolower(c);
		lhsCopy[i] = c;
	}
	for (int i = 0; i < rhsCopy.length(); i++){
		char c = rhsCopy[i];
		c = tolower(c);
		rhsCopy[i] = c;
	}
	
	//compare the strings to see if lhs > rhs
	if(lhsCopy.compare(rhsCopy) > 0){
		return true;
	}	
	else{
		return false;
	}
}

bool Account::operator<(const Account* rhs){
	//Make a duplicate string of rhs and lhs
	string lhsCopy = siteName;
	string rhsCopy = rhs->siteName;
	
	//Set the duplicate strings to lower case
	for (int i = 0; i < lhsCopy.length(); i++){
		char c = lhsCopy[i];
		c = tolower(c);
		lhsCopy[i] = c;
	}
	for (int i = 0; i < rhsCopy.length(); i++){
		char c = rhsCopy[i];
		c = tolower(c);
		rhsCopy[i] = c;
	}
	//compare the strings to see if lhs < rhs
	if(lhsCopy.compare(rhsCopy) < 0){
		return true;
	}	
	else{
		return false;
	}
}

bool Account::operator==(const Account* rhs){
	
	//Make a duplicate string of rhs and lhs
	string lhsCopy = siteName;
	string rhsCopy = rhs->siteName;
	
	//Set the duplicate strings to lower case
	for (int i = 0; i < lhsCopy.length(); i++){
		char c = lhsCopy[i];
		c = tolower(c);
		lhsCopy[i] = c;
	}
	for (int i = 0; i < rhsCopy.length(); i++){
		char c = rhsCopy[i];
		c = tolower(c);
		rhsCopy[i] = c;
	}
	
	//Compare the strings to check for equality 
	if(lhsCopy.compare(rhsCopy) == 0){
		return true;
	}
	else{
		return false;
	}
}
