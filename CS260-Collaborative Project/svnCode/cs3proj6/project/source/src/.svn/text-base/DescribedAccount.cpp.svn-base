#include "../headers/DescribedAccount.h"

DescribedAccount::DescribedAccount()
		:Account(), siteDescription("siteDescription"){	
}

DescribedAccount::DescribedAccount(int numattributes)
		:Account(), siteDescription("siteDescription"){
}
	
DescribedAccount::DescribedAccount(string sitename)
		:Account(sitename), siteDescription("siteDescription"){
}
	
DescribedAccount::DescribedAccount(int numattributes, string sitename, string username, string sitepassword, string siteurl, string sitedescription)
		:Account(numattributes, sitename, username, sitepassword, siteurl), siteDescription(sitedescription){
}

string DescribedAccount::getSiteDescription()const{
	return siteDescription;
}

string DescribedAccount::getSubExpiration()const{
	return "ERROR: Not a valid data field for this class.";
}

string DescribedAccount::getMonthlyFee()const{
	return "ERROR: Not a valid data field for this class.";
}

void DescribedAccount::setSiteDescription(string sitedescription){
	siteDescription = sitedescription;
}

void DescribedAccount::setSubExpiration(string subexpiration){
	//Not implemented	
}

void DescribedAccount::setMonthlyFee(string monthlyfee){
	//Not implemented
}

ostream& DescribedAccount::printToFile(ostream &outS){
	outS << endl 
	<< numAttributes << endl
	<< siteName << endl
	<< userName << endl
	<< sitePassword << endl
	<< siteURL << endl
	<< siteDescription;
	return outS;
}

void DescribedAccount::printToScreen() const{
	cout
	<< "Site Name:  " << siteName << endl
	<< "User Name:  " << userName << endl
	<< "Password:  " << sitePassword << endl
	<< "Site URL:  " << siteURL << endl
	<< "Site Description:  " << siteDescription << endl;
}
