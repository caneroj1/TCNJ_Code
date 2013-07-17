#include "../headers/Reader.h"

Reader::Reader(string fName)
{
	fileName = fName.append(".nyn");
}

bool Reader::openFile()
{
	inS.open(fileName.c_str());
	
	if (inS.fail())
	{
		inS.clear();
		return false;
	}
	else
		return true;
}

string Reader::readAll(LinkedList* accounts)
{
	string pass;
	getline(inS, pass);
	
	while (!inS.eof())
    {
        int numAttributes;
        string numAttributesLine, name, uName, pword, url, descrip;
        string monthlyCost, expirationDate, status;
        Account* acct;
        
        getline(inS, numAttributesLine);
        numAttributes = atoi(numAttributesLine.c_str());
        getline(inS, name);
		getline(inS, uName);
		getline(inS, pword);
		getline(inS, url);
        
        switch (numAttributes)
        {
            case 5:
                getline(inS, descrip);
                acct = new DescribedAccount(numAttributes, name, uName, pword, url, descrip);
                break;
            case 7:
                getline(inS, descrip);
                getline(inS, monthlyCost);
                getline(inS, expirationDate);
                acct = new SubscribedAccount(numAttributes, name, uName, pword, url, descrip, monthlyCost, expirationDate);
                break;
            default:
                acct = new StandardAccount(numAttributes, name, uName, pword, url);
				break;
        }
		
		accounts->insertElement(acct);
	}
	return pass;
}

void Reader::closeFile()
{
	inS.close();
}
