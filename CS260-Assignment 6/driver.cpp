//
//  driver.cpp
//  This is the implementation for the Driver
//  It will run the program
//  Joe Canero
//  CSC260, Dr. Pulimood
//  Created by Joseph Canero on 11/14/12.
//
//

#include "driver.h"
#include "Set.h"
#include <iostream>

using namespace std;

int main()
{
    string fileName;
    ifstream inFile;
    int removeElem = 0;
    char readChar = 'n';
    Set set1;
    
    cout << endl << endl << endl << "********** Welcome to the Set Operations Program. **********" << endl << endl;
    
    cout << "Add elements to Set 1." << endl;
    cin >> set1;
    
    //************************************************************************************************************
    cout << "Do you want to read input from a file? (y/n): ";
    cin >> readChar;
    
    if(readChar == y) {
        bool success = false;
        do {
            cout << "Enter file name for file input: ";
            cin >> fileName;
            inFile.open(fileName.c_str());
            if (inFile.fail())
            {
                cout << "File opening operation failed." << endl;
                inFile.clear();
                inFile.ignore(80, ' ');
            }
            else
                success = true;
            
            inFile >> set1;
            
        } while (!success);
        inFile.close();
    }
    
    if (readChar == n)
    {
        cout << "There will be no input from a file." << endl;
    }
    cout << "Set 1: " << set1;

    cout << "Using copy constructor for set 2." << endl << endl;
    Set set2 (set1);
    
    cout << "Set 2 after copy constructor: " << set2 <<endl;
    
    cout << "Clearing Set 2." << endl;
    set2.clearSet();
    
    //************************************************************************************************************
    cout << "Do you want to read input from a file? (y/n): ";
    cin >> readChar;
    
    if(readChar == y) {
        bool success = false;
        do {
            cout << "Enter file name for file input: ";
            cin >> fileName;
            inFile.open(fileName.c_str());
            if (inFile.fail())
            {
                cout << "File opening operation failed." << endl;
                inFile.clear();
                inFile.ignore(80, ' ');
            }
            else
                success = true;
            
            inFile >> set2;
            
        } while (!success);
        inFile.close();
        cout << "Set 2 after reading from a file: " << set2 << endl;
    }
    
    if (readChar == n)
    {
        cout << "There will be no input from a file." << endl;
    }
    
    //************************************************************************************************************
    cout << "Do you want to enter your own elements? (y/n): ";
    cin >> readChar;
    
    if(readChar == y) {
        cin >> set2;
        cout << "Set 2 after user input: " << set2 << endl;
    }
    
    if (readChar == n) {
        cout << "There will be no input from the user." << endl;
    }
    
    if (set2.isEmpty()) {
        cout << "Set 2 is empty." << endl;
        
        cout << "Inseting 98 and 104 into Set 2." << endl << endl;
        
        set2.insertElement(98);
        set2.insertElement(104);
        
        cout << "Set 2 after insertion: " << set2 << endl;
    }
    
    //************************************************************************************************************
    int toBR = 0;
    int remCount = 0;
    bool remSuc = false;
    cout << "Removing elements from Set 2. " << endl << "Number of elements to be removed: ";
    cin >> toBR;
    
    int i = 0;
    while (i < toBR)
    {
        do {
            cout << "Removing an element." << " Element to be removed: ";
            cin >> removeElem;
            remSuc = set2.removeElement(removeElem);
            cout << endl;
            if (!remSuc) {
                cout << "Continue removing elements? (y/n) ";
                cin >> readChar;
                cout << endl;
            }
            else
                remCount++;
        } while (!remSuc && readChar == y);
        i++;
    }
    
    cout << "Set 2 after removing " << remCount << " element(s): " << set2 << endl;
    
    //************************************************************************************************************
    cout << "Unioning Set 1 and Set 2." << endl;
    
    Set set3 (set1 + set2);
    cout << "Union of Set 1 and Set 2: " << set3 << endl << "********************" << endl;
    
    cout << "Setting Set 3 equal to Set 1. " << endl << "********************" << endl << "Set 3 before operation: " << set3 << endl << "Set 1: " << set1 << endl;
    set3 = set1;
    cout << "Set 3 now equals Set 1" << endl << "Set 3 after operation: " << set3 << endl << "Set 1: " << set1 << endl;
    
    //************************************************************************************************************
    set1.clearSet();
    set2.clearSet();
    cout << "Reentering Set 1 and Set 2." << endl << "For Set 1." << endl;
    cin >> set1;
    cout << "For Set 2." << endl;
    cin >> set2;
    
    cout << "Intersecting Set 1 and Set 2." << endl;
    Set set4 (set1/set2);
    cout << "Intersection of Set 1 and Set 2: " << set4 << endl;
    
    
    return 0;
}






























