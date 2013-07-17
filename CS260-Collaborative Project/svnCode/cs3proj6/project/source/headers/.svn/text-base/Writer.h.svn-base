#if !defined (WRITER_H)
#define WRITER_H
#include <iostream>
#include <fstream>
#include "List.h"
#include "Account.h"
#include "DescribedAccount.h"
#include "SubscribedAccount.h"
using namespace std;

class Writer
{
	private:
		string fileName;
		ofstream outS;
		
	public:
		Writer(string);
		bool openFile();
		
		void writeAll(string, LinkedList*);
		void closeFile();
};

#endif
