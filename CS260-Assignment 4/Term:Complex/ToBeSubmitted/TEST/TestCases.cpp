//  Joe Canero
//  TestCases.cpp
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/9/12.
//
//

#include "Polynomial.cpp"

int main()
{
    //This is the Driver that will test the operations on Polynomials and Terms. All essential operations will be tested
    //The data that should be used are placed in comments above the code statement where they will be input
    
    Polynomial p1;
    Polynomial p2;
    Polynomial p3;
    bool success = true;
    ifstream inFile;
    string fName;
    
    cout << "This is the driver that will test every case in the Test Cases document." << endl;
    
    cout << "TEST: Adding a Polynomial to a Polynomial with 0 terms." << endl;
    
    //5x3 + 2x2 + x
    cin >> p1;
    //0
    cin >> p2; 
    
    p3 = p1 + p2;
    
    cout << "Expected Result: 5x3 + 2x2 + x" << endl;
    cout << "Actual Result: " << p3 << endl;
    
    cout << "TEST: Adding two Polynomials." << endl;
    
    cout << "Polynomial 1" << endl;
    //8x4 + 9x3 + 6x
    cin >> p1; 
    cout << "Polynomial 2" << endl;
    //5x5 + 6x3 + 2x2
    cin >> p2; 
    
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    p3 = p1 + p2;
    
    cout << "Expected Result: 5x5 + 8x4 + 15x3 + 2x2 + 6x" << endl;
    cout << "Actual Result: " << p3 << endl;
    
    cout << "TEST: Adding a Polynomial to an integer, 5." << endl;
    
    //-6x8 + 4x5 -2x + 3
    cin >> p1; 
    cout << "Polynomial 1: " << p1 << endl;
    p3 = p1 + 5;
    
    cout << "Expected Result: -6x8 + 4x5 -2x + 8" << endl;
    cout << "Actual Result: " << p3;
    
    cout << "TEST: Adding an integer, 5, to a Polynomial" << endl;
    
    //-6x8 + 4x5 -2x + 3
    cin >> p1; 
    cout << "Polynomial 1: " << p1 << endl;
    p3 = 5 + p1;
    
    cout << "Expected Result: -6x8 + 4x5 -2x + 8" << endl;
    cout << "Actual Result: " << p3 << endl;
    
    cout << "TEST: Setting 2 Polynomials equal to each other." << endl;
    
    //9x7 + 8x4 + 2x3  + 4x2 + 6x + 2
    cin >> p1;
    //4x9
    cin >> p2; 
    
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    cout << "SETTING POLYNOMIALS EQUAL TO EACH OTHER..." << endl;
    
    p1 = p2;
    
    cout << "Results: " << endl;
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    cout << "TEST: Multiplying 2 Polynomials." << endl;

    //x3 – 3x4
    cin >> p1;
    //x2 – 2x
    cin >> p2; 
    
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    
    p3 = p1 * p2;
    
    cout << "Expected Result: - 3x6 + 7x5 - 2x4" << endl;
    cout << "Actual Result: " << p3 << endl;
    
    cout << "TEST: Multiplying an integer, 4, by Polynomial 1" << endl;
    
    //7x3 – 2x2 + 8x + 5
    cin >> p1; 
    
    p3 = 4 * p1;
    
    cout << "Expected Result: 28x3 - 8x2 + 32x + 20" << endl;
    cout << "Actual Result: " << p3 << endl;
    
    cout << "TEST: Multiplying Polynomial 1 by an integer, 4." << endl;
    
    p3 = p1 * 4;
    
    cout << "Expected Result: 28x3 - 8x2 + 32x + 20" << endl;
    cout << "Actual Result: " << p3 << endl;
    
    cout << "TEST: Overwriting an existing Polynomial by reading from a file." << endl;
    
    //3x4 + x2 
    cin >> p1; 
    
    cout << "Polynomial 1: " << p1 << endl;
    
    //The file should be textPoly2.txt
    
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
    
    inFile >> p1;
    
    cout << "The overwritten Polynomial is: " << p1;
    
    cout << "TEST: Display a Polynomial in descending order." << endl;
    
    //3x2 + 5x7 + 9x3 + 10x -8x8 + 20x4 – x5
    cin >> p1; 
    
    cout << "After sorting, Polynomial 1: " << p1 << endl;
    
    cout << "TEST: Evaulate Polynomial 1 for an integer, 3." << endl;
    
    //3x2 + 5x7 + 9x3 + 10x -8x8 + 20x4 – x5
    cin >> p1; 
    
    cout << "Expected Result: -39876" << endl;
    cout << "Actual Result: " << p1.evalPoly(3) << endl;
    
    cout << "TEST: Simplify and order a Polynomial with multiple terms of equal degree." << endl;
    
    //5x3 + 45x3 + 10x4 + 2x4 + x
    cin >> p1; 
    
    cout << "Expected Result: 12x4 + 50x3 + x" << endl;
    cout << "After simplifying and sorting, Polynomial: " << p1 << endl;
    
    cout << "TEST: Set a Polynomial equal to an integer, 12." << endl;
    
    cin >> p1;
    cout << "Polynomial 1: " << p1 << endl;
    p1 = 12;
    cout << "After setting Polynomial 1 equal to 12, the result is: " << p1 << endl;
    
    cout << endl << endl << endl << "The tests have concluded." << endl << "Thank you for using this program." << endl;
    
    return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
