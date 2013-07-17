//  Joe Canero
//  UserInterface.cpp
//  CSC260
//  Dr. Pulimood
//
//  Assignment 4
//  Created by Joseph Canero on 10/9/12.
//
//

#include "UserInterface.h"
#include "PolynomialTemp.cpp"
#include "Complex4Temp.cpp"

using namespace std;

int main()
{
    char mult = 'm';
    char add = 'a';
    char ints = 'i';
    char comps = 'c';
    char floats = 'f';
    char eval = 'v';
    char exit = 'x';
    char reenter = 'r';
    char readFile = 'l';
    char deriv = 'd';
    char userIn;
    bool exitStatus = false;
    int x = 0;
    float y = 0;
    double v = 0;
    
    ifstream inFile;
    
    //*********************************************************************************
    
    Polynomial<int> p1;
    Polynomial<float> p2;
    Polynomial<Complex> p3;
    
    Polynomial<int> p4;
    Polynomial<float> p5;
    Polynomial<Complex> p6;
    
    //results Polynomials
    Polynomial<int> p7;
    Polynomial<float> p8;
    Polynomial<Complex> p9;
    
    //*********************************************************************************
    
    
    
    //*********************************************************************************
    
    cout << "Entering Polynomial 1 (INTEGER): " << endl;
    
    cin >> p1;
    cout << p1 << endl;
    
    cout << "Entering Polynomial 2 (FLOAT): " << endl;
    
    cin >> p2;
    cout << p2 << endl;
    
    cout << "Entering Polynomial 3 (COMPLEX): " << endl;
    
    cin >> p3;
    cout << p3 << endl;
    
    cout << "Entering Polynomial 4 (INTEGER): " << endl;
    
    cin >> p4;
    cout << p4 << endl;
    
    cout << "Entering Polynomial 5 (FLOAT): " << endl;
    
    cin >> p5;
    cout << p5 << endl;
    
    cout << "Entering Polynomial 6 (COMPLEX): " << endl;
    
    cin >> p6;
    cout << p6 << endl;
    
    
    do {
        cout << "What would you like to do?" << endl << endl << "CHOICES: (m)ultiply, (a)dd, e(v)aluate, (r)eenter Polynomials, read from fi(l)e, (d)erivative, e(x)it" << endl;
        cin >> userIn;
        
        if (userIn == mult)
        {
            cout << "Multiply which type of Polynomial?" << endl << endl << "CHOICES: (c)omplex, (i)nteger, (f)loat" << endl;
            cin >> userIn;
            cout << endl;
            //*********************************************************************************
            if (userIn == comps)
            {
                cout << "Polynomial 3 (COMPLEX) and Polynomial 6 (COMPLEX) multiplied together is: " << endl;
                p9 = p3 * p6;
                cout << p9 << endl;
                
                cout << "Multiplying Polynomial 3 (COMPLEX) by an integer." << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                Complex z(x,0);
                
                cout << "Polynomial 3 (COMPLEX) multiplied by " << x << " is: " << endl;
                p9 = p3*z;
                cout << p9 << endl;
                
                cout << "Multiplying an integer by Polynomial 6 (COMPLEX)" << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                Complex cc(x,0);
                
                cout << x <<" multiplied by Polynomial 6 (COMPLEX) is: " << endl;
                p9 = cc*p6;
                cout << p9 << endl;
            }
            
            //*********************************************************************************
            if (userIn == ints)
            {
                cout << "Polynomial 1 (INTEGER) and Polynomial 4 (INTEGER) multiplied together is: " << endl;
                p7 = p1 * p4;
                cout << p7 << endl;
                
                cout << "Multiplying Polynomial 1 (INTEGER) by an integer." << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                cout << "Polynomial 1 (INTEGER) multiplied by " << x << " is: " << endl;
                p7 = p1*x;
                cout << p7 << endl;
                
                cout << "Multiplying an integer by Polynomial 4 (INTEGER)" << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                cout << x <<" multiplied by Polynomial 4 (INTEGER) is: " << endl;
                p7 = x*p4;
                cout << p7 << endl;
            }
            
            //*********************************************************************************
            if (userIn == floats)
            {
                cout << "Polynomial 2 (FLOAT) and Polynomial 5 (FLOAT) multiplied together is: " << endl;
                p8 = p2 * p5;
                cout << p8 << endl;
                
                cout << "Multiplying Polynomial 2 (FLOAT) by a float." << endl;
                
                cout << "Enter the float: ";
                cin >> y;
                
                cout << "Polynomial 2 (FLOAT) multiplied by " << x << " is: " << endl;
                p8 = p2*y;
                cout << p8 << endl;
                
                cout << "Multiplying a float by Polynomial 5 (FLOAT)" << endl;
                
                cout << "Enter the float: ";
                cin >> y;
                
                cout << y <<" multiplied by Polynomial 5 (FLOAT) is: " << endl;
                p8 = y*p5;
                cout << p8 << endl;
            }
        }
        
        if (userIn == add)
        {
            cout << "Add which type of Polynomial?" << endl << endl << "CHOICES: (c)omplex, (i)nteger, (f)loat" << endl;
            cin >> userIn;
            cout << endl;
            
            //*********************************************************************************
            if (userIn == ints)
            {
                cout << "Polynomial 1 (INTEGER) and Polynomial 4 (INTEGER) added together is: " << endl;
                p7 = p1 + p4;
                cout << p7 << endl;
                
                cout << "Adding Polynomial 1 (INTEGER) to an integer." << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                cout << "Polynomial 1 (INTEGER) added to " << x << " is: " << endl;
                p7 = p1+x;
                cout << p7 << endl;
                
                cout << "Adding an integer to Polynomial 4 (INTEGER)" << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                cout << x <<" added to Polynomial 4 (INTEGER) is: " << endl;
                p7 = x+p4;
                cout << p7 << endl;
            }
            
            //*********************************************************************************
            if(userIn == floats)
            {
                cout << "Polynomial 2 (FLOAT) and Polynomial 5 (FLOAT) added together is: " << endl;
                p8 = p2 + p5;
                cout << p8 << endl;
                
                cout << "Adding Polynomial 2 (FLOAT) to a float." << endl;
                
                cout << "Enter the float: ";
                cin >> y;
                
                cout << "Polynomial 2 (FLOAT) added to " << x << " is: " << endl;
                p8 = p2+y;
                cout << p8 << endl;
                
                cout << "Adding a float to Polynomial 5 (FLOAT)" << endl;
                
                cout << "Enter the float: ";
                cin >> y;
                
                cout << y <<" added to Polynomial 5 (FLOAT) is: " << endl;
                p8 = y+p5;
                cout << p8 << endl;
            }
            
            //*********************************************************************************
            if(userIn == comps)
            {
                cout << "Polynomial 3 (COMPLEX) and Polynomial 6 (COMPLEX) added together is: " << endl;
                p9 = p3 + p6;
                cout << p9 << endl;
                
                cout << "Adding Polynomial 3 (COMPLEX) to an integer." << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                Complex z(x, 0);
                
                cout << "Polynomial 3 (COMPLEX) added to " << x << " is: " << endl;
                p9 = p3+z;
                cout << p9 << endl;
                
                cout << "Adding an integer to Polynomial 6 (COMPLEX)" << endl;
                
                cout << "Enter the integer: ";
                cin >> x;
                
                Complex cc(x,0);
                
                cout << x <<" added to Polynomial 6 (COMPLEX) is: " << endl;
                p9 = cc+p6;
                cout << p9 << endl;
            }
        }
        
        //*********************************************************************************
        
        if (userIn == eval)
        {
            cout << "Evaluate which type of Polynomial?" << endl << endl << "CHOICES: (c)omplex, (i)nteger, (f)loat" << endl;
            cin >> userIn;
            cout << endl;
            
            if (userIn == ints)
            {
                cout << "Enter the value of x: ";
                cin >> v;
                cout << endl;
                
                cout << "Evaluating Polynomial 1 (INTEGER) for x = " << v << " returns: " << p1.evalPoly(v) << endl;
                cout << "Evaluating polynomial 4 (INTEGER) for x = " << v << " returns: " << p4.evalPoly(v) << endl;
            }
            
            if (userIn == floats)
            {
                cout << "Enter the value of x: ";
                cin >> v;
                cout << endl;
                
                cout << "Evaluating Polynomial 2 (FLOAT) for x = " << v << " returns: " << p2.evalPoly(v) << endl;
                cout << "Evaluating polynomial 5 (FLOAT) for x = " << v << " returns: " << p5.evalPoly(v) << endl;
            }
            
            if (userIn == comps)
            {
                cout << "Enter the value of x: ";
                cin >> v;
                cout << endl;
                
                cout << "Evaluating Polynomial 3 (COMPLEX) for x = " << v << " returns: " << p3.evalPoly(v) << endl;
                cout << "Evaluating polynomial 6 (COMPLEX) for x = " << v << " returns: " << p6.evalPoly(v) << endl;
            }
        }
        
        //*********************************************************************************
        
        if (userIn == reenter)
        {
            cout << "Reenter which type of Polynomial?" << endl << endl << "CHOICES: (c)omplex, (i)nteger, (f)loat" << endl;
            cin >> userIn;
            cout << endl;
            
            if (userIn == ints)
            {
                cout << "Entering Polynomial 1 (INTEGER): " << endl;
                
                cin >> p1;
                cout << p1 << endl;
                
                cout << "Entering Polynomial 4 (INTEGER): " << endl;
                
                cin >> p4;
                cout << p4 << endl;
            }
            
            if (userIn == floats)
            {
                cout << "Entering Polynomial 2 (FLOAT): " << endl;
                
                cin >> p2;
                cout << p2 << endl;
                
                cout << "Entering Polynomial 5 (FLOAT): " << endl;
                
                cin >> p5;
                cout << p5 << endl;
            }
            
            if (userIn == comps)
            {
                cout << "Entering Polynomial 3 (COMPLEX): " << endl;
                
                cin >> p3;
                cout << p3 << endl;
                
                cout << "Entering Polynomial 6 (COMPLEX): " << endl;
                
                cin >> p6;
                cout << p6 << endl;
            }
        }
        
        //*********************************************************************************
        
        if (userIn == readFile)
        {
            cout << "Which type of Polynomial do you wish to read in from a file?" << endl << endl << "CHOICES: (c)omplex, (i)nteger, (f)loat" << endl;
            cin >> userIn;
            cout << endl;
            
            if (userIn == ints)
            {
                cout << "Choice of 3 files for input. Which file (1, 2, 3)?" << endl;
                cin >> userIn;
                cout << endl;
                
                if (userIn == '1')
                {
                    inFile.open("textPoly1.txt");
                    
                    cout << "Overwriting Polynomial 1 (INTEGER) from File 1." << endl;
                    inFile >> p1;
                    cout << "Polynomial 1 (INTEGER) is now: " << endl << p1;
                    
                    inFile.close();
                }
                
                if (userIn == '2')
                {
                    inFile.open("textPoly2.txt");
                    
                    cout << "Overwriting Polynomial 1 (INTEGER) from File 2." << endl;
                    inFile >> p1;
                    cout << "Polynomial 1 (INTEGER) is now: " << endl << p1;
                    
                    inFile.close();
                }
                
                if (userIn == '3')
                {
                    inFile.open("textPoly3.txt");
                    
                    cout << "Overwriting Polynomial 1 (INTEGER) from File 3." << endl;
                    inFile >> p1;
                    cout << "Polynomial 1 (INTEGER) is now: " << endl << p1;
                    
                    inFile.close();
                }
            }
            
            if (userIn == floats)
            {
                inFile.open("textPoly5.txt");
                
                cout << "Overwriting Polynomial 2 (FLOAT) from file." << endl;
                inFile >> p2;
                cout << "Polynomial 2 (FLOAT) is now: " << endl << p2;
                
                inFile.close();
            }
            
            if (userIn == comps)
            {
                inFile.open("textPoly4.txt");
                
                cout << "Overwriting Polynomial 3 (COMPLEX) from file." << endl;
                inFile >> p3;
                cout << "Polynomial 3 (COMPLEX) is now: " << endl << p3;
                
                inFile.close();
            }
        }
        
        //*********************************************************************************
        
        if(userIn == deriv)
        {
            cout << "What Polynomial would you like to take the derivative of?" << endl  << endl << "CHOICES: (c)omplex, (i)nteger, (f)loat" << endl;
            cin >> userIn;
            cout << endl;
            
            if(userIn == ints)
            {
                cout << "Taking the derivative of Polynomial 1 (INTEGER)." << endl;
                cout << "f(x) = " << p1 << endl;
                p7 = p1.derivative();
                cout << "f'(x) = " << p7 << endl;
                
                cout << "Taking the derivative of Polynomial 4 (INTEGER)." << endl;
                cout << "f(x) = " << p4 << endl;
                p7 = p4.derivative();
                cout << "f'(x) = " << p7 << endl;
            }
            
            if(userIn == floats)
            {
                cout << "Taking the derivative of Polynomial 2 (FLOAT)." << endl;
                cout << "f(x) = " << p2 << endl;
                p8 = p2.derivative();
                cout << "f'(x) = " << p8 << endl;
                
                cout << "Taking the derivative of Polynomial 5 (FLOAT)." << endl;
                cout << "f(x) = " << p5 << endl;
                p8 = p5.derivative();
                cout << "f'(x) = " << p8 << endl;
            }
            
            if(userIn == comps)
            {
                cout << "Taking the derivative of Polynomial 3 (COMPLEX)." << endl;
                cout << "f(x) = " << p3 << endl;
                p9 = p3.derivative();
                cout << "f'(x) = " << p9 << endl;
                
                cout << "Taking the derivative of Polynomial 6 (COMPLEX)." << endl;
                cout << "f(x) = " << p6 << endl;
                p9 = p6.derivative();
                cout << "f'(x) = " << p9 << endl;
            }
        }
        
        //*********************************************************************************
        
        if (userIn == exit)
        {
            cout << "Before exiting, some basic assignment statements will occur." << endl << endl;
            cout << "Assigning Polynomial 4 (INTEGER) to Polynomial 1 (INTEGER)." << endl;
            cout << "Assigning an integer to Polynomial 4 (INTEGER) Enter the integer: ";
            cin >> x;
            cout << endl << endl;
            
            p1 = p4;
            p4 = x;
            
            cout << "Polynomial 1 (INTEGER): " << p1 << endl;
            cout << "Polynomial 4 (INTEGER): " << p4 << endl;
            
            cout << "Assigning Polynomial 5 (FLOAT) to Polynomial 2 (FLOAT)." << endl;
            cout << "Assigning a float to Polynomial 5 (FLOAT) Enter the float: ";
            cin >> y;
            cout << endl << endl;
            
            p2 = p5;
            p5 = y;
            
            cout << "Polynomial 2 (FLOAT): " << p2 << endl;
            cout << "Polynomial 5 (FLOAT): " << p5 << endl;
            
            cout << "Assigning Polynomial 6 (COMPLEX) to Polynomial 3 (COMPLEX)." << endl;
            cout << "Assigning an integer to Polynomial 6 (COMPLEX) Enter the integer: ";
            cin >> x;
            cout << endl << endl;
            
            Complex z(x, 0);
            
            p3 = p6;
            p6 = z;
            
            cout << "Polynomial 3 (COMPLEX): " << p3 << endl;
            cout << "Polynomial 6 (COMPLEX): " << p6 << endl << endl << endl;
            
            cout << "Outputting Polynomial 1 to a file." << endl;
            
            p1.writeToFile();
            
            cout << "Done." << endl;
            
            cout << "*********************************************************************************" << endl << "Execution Terminated. Exiting." << endl;
            exitStatus = true;
        }
        
    }while (!exitStatus);
    
    //*********************************************************************************
    //*********************************************************************************
    //*********************************************************************************
    
    return 0;
}