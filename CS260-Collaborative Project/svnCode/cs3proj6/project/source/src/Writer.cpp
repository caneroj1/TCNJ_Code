#include "../headers/Writer.h"

Writer::Writer(string fname)
{
	fileName = fname.append(".nyn");
}

bool Writer::openFile()
{
	outS.open(fileName.c_str());
	
	if (outS.fail())
		return false;
	else
		return true;
}

void Writer::writeAll(string password, LinkedList* accounts)
{
	outS << password;
	int elems = accounts->sizeOfList();
    
	for (int i=0; i<elems; i++)
	{
		Account* acct = accounts->returnElement(i);
        acct->printToFile(outS);
        acct = NULL;
	}
}

void Writer::closeFile()
{
	outS.close();
}
