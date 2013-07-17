//  Joe Canero
//  Driver.cpp
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/9/12.
//
//

#include "Polynomial.cpp"

using namespace std;

int main()
{
    string fName; //will accept the file name that will be read from
    bool success = true;
    ifstream inFile;
    
    Polynomial p1; //Polynomials that will be used for processing
    Polynomial p2;    
    Polynomial p3;
    
    cin >> p1;
    cin >> p2;
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    cout << "Entering Polynomial 2 from a file. " << endl;
    
    do{
        cout << "What is the name of the file? ";
        cin >> fName;
        
        inFile.open(fName.c_str());
        if(inFile.fail())
        {
            inFile.clear();
            cin.ignore(80, '\n');
            cerr << endl << "That is invalid. Please reenter. " << endl;
            success = false;
        }
        else
            success = true;
    }while(!success);
    
    inFile >> p2; //reads in from the user-specified file
    inFile.close();
    
    cout << "Polynomial 2 after reading from the file: ";
    cout << p2 << endl;
    
    cout << "When adding Polynomials 1 and 2, the result is: " << endl;
    p3 = p1 + p2;
    cout << p3 << endl;
    
    cout << "Setting Polynomial 1 equal to Polynomial 2..." << endl;
    p1 = p2;
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    cout << "When multiplying Polynomials 1 and 2, the result is: ";
    p3 = p1 * p2;
    cout << p3 << endl;
    
    cout << "When multiplying Polynomial 1 by a number, the result is: ";
    p3 = p1 * 9;
    cout << p3 << endl;
    
    cout << "When multiplying a number by Polynomial 1, the result is: ";
    p3 = 3 * p1;
    cout << p3 << endl;
    
    cout << "When adding Polynomial 1 to a number, the result is: ";
    p3 = p1 + 5;
    cout << p3 << endl;
    
    cout << "When adding a number to Polynomial 2, the result is: ";
    p3 = 7 + p2;
    cout << p3 << endl;
    
    int x = 0;
    cout << "Let's evalulate Polynomial 1 for a value. Please enter a value: ";
    cin >> x;
    cout << endl;
    
    cout << "Evaluating Polynomial 1 for x = " << x << " returns: " << p1.evalPoly(x) << endl;
    
    cout << "Writing Polynomial 1 to a file. ";
    
    p1.writeToFile();
    
    cout << "Thank you for using this program!" << endl;
    
    return 0;
    
}
