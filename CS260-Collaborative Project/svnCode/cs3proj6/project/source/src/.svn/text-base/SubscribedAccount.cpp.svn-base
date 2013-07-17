#include "../headers/SubscribedAccount.h"

SubscribedAccount::SubscribedAccount()
		:Account(), siteDescription("siteDescription"), subExpiration("subExpiration"), monthlyFee("monthlyFee") {	
}

SubscribedAccount::SubscribedAccount(int numattributes)
		:Account(), siteDescription("siteDescription"), subExpiration("subExpiration"), monthlyFee("monthlyFee"){
}
	
SubscribedAccount::SubscribedAccount(string sitename)
		:Account(sitename), siteDescription("siteDescription"){
}
	
SubscribedAccount::SubscribedAccount(int numattributes, string sitename, string username, string sitepassword, string siteurl, string sitedescription, string subexpiration , string monthlyfee)
		:Account(numattributes, sitename, username, sitepassword, siteurl), siteDescription(sitedescription), subExpiration(subexpiration), monthlyFee(monthlyfee){
}

string SubscribedAccount::getSiteDescription()const{
	return siteDescription;
}

string SubscribedAccount::getSubExpiration()const{
	return subExpiration;
}

string SubscribedAccount::getMonthlyFee()const{
	return monthlyFee;
}

void SubscribedAccount::setSiteDescription(string sitedescription){
	siteDescription = sitedescription;
}

void SubscribedAccount::setSubExpiration(string subexpiration){
	subExpiration = subexpiration;
}

void SubscribedAccount::setMonthlyFee(string monthlyfee){
	monthlyFee = monthlyfee;
}

ostream& SubscribedAccount::printToFile(ostream &outS) {
	outS << endl
	<< numAttributes << endl
	<< siteName << endl
	<< userName << endl
	<< sitePassword << endl
	<< siteURL << endl
	<< siteDescription << endl
	<< subExpiration << endl
	<< monthlyFee;
	return outS;
}

void SubscribedAccount::printToScreen() const{
	cout
	<< "Site Name:  " << siteName << endl
	<< "User Name:  " << userName << endl
	<< "Password:  " << sitePassword << endl
	<< "Site URL:  " << siteURL << endl
	<< "Site Description:  " << siteDescription << endl
	<< "Expiration Date:  " << subExpiration << endl
	<< "Monthly Fee:  $" << monthlyFee << endl;
}
