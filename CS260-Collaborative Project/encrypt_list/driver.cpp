/*
 *  testDriver.cpp
 *  
 *
 *  Created by Joseph Canero on 11/17/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "List.cpp"

using namespace std;

int main()
{
	cout << "int list" << endl;
	
	LinkedList<int> intList;
	
	intList.insertElement(5);
	intList.insertElement(10);
	
	cin >> intList;
	
	cout << intList;
	
	cout << "float list" << endl;
	
	LinkedList<float> PINGAS;
	
	cin >> PINGAS;
	
	cout << PINGAS;
    
    cout << "LENGTH OF PINGAS: " << PINGAS.sizeOfList() << endl;
    
    float peen = PINGAS.returnElement(2);
    
    cout << peen << endl;
	
	return 0;
	
}
