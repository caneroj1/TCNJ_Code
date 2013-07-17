#if !defined (READER_H)
#define READER_H
#include <iostream>
#include <fstream>
#include "List.h"
#include "Account.h"
#include "StandardAccount.h"
#include "DescribedAccount.h"
#include "SubscribedAccount.h"
#include <cstdlib>
using namespace std;

class Reader
{
	private:
		string fileName;
		ifstream inS;
		
	public:
		Reader(string);
		bool openFile();
		string readAll(LinkedList*);
		void closeFile();
};

#endif
