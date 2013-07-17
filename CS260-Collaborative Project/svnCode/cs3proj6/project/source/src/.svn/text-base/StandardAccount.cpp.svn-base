#include "../headers/StandardAccount.h"

StandardAccount::StandardAccount():Account(){	
}
	
StandardAccount::StandardAccount(int numattributes):Account(){
}
	
StandardAccount::StandardAccount(string sitename):Account(sitename){
}
	
StandardAccount::StandardAccount(int numattributes, string sitename, string username, string sitepassword, string siteurl):Account(numattributes, sitename, username, sitepassword, siteurl){
}

string StandardAccount::getSiteDescription()const{
	return "ERROR: Not a valid data field for this class.";
}

string StandardAccount::getSubExpiration()const{
	return "ERROR: Not a valid data field for this class.";
}

string StandardAccount::getMonthlyFee()const{
	return "ERROR: Not a valid data field for this class.";
}

void StandardAccount::setSiteDescription(string sitedescription){
	//Not implemented
}

void StandardAccount::setSubExpiration(string subexpiration){
	//Not implemented	
}

void StandardAccount::setMonthlyFee(string monthlyfee){
	//Not implemented
}

ostream& StandardAccount::printToFile(ostream &outS) {
	outS << endl 
	<< numAttributes << endl
	<< siteName << endl
	<< userName << endl
	<< sitePassword << endl
	<< siteURL;
	return outS;
}

void StandardAccount::printToScreen() const{
	cout 
	<< "Site Name:  " << siteName << endl
	<< "User Name:  " << userName << endl
	<< "Password:  " << sitePassword << endl
	<< "Site URL:  " << siteURL << endl;
}
