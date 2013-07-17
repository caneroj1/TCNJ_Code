//
//  numericalIntegration.cpp
//  
//
//  Created by Joseph Canero on 5/16/13.
//
//

#include <iostream>
#include <cmath>

float userDefinedFunction(float);
float midpointApprox(int, int, int);
float trapezoidalRule(int, int, int);
float simpsonRule(int, int, int);
void getUserInput(int&, int&);
void getApproximation(char&);
void getNumberSubdivisions(int&);

using namespace std;

int main () {
    
    //numerical integration using the midpoint approximation, trapezoidal rule, or simpson's rule
    
    //variables for execution
    
    int a = 0;
    int b = 1;
    int i = 1;
    char u = 'b';
    
    cout << "\n\n\n*****************************************************************\n\n            APPLICATION FOR NUMERICAL INTEGRATION." << endl;
    cout << "           This will integrate a user-defined function...\n\n";
    
    getUserInput(a, b);
    getNumberSubdivisions(i);
    getApproximation(u);
    
    if(u == 'm')
        cout << "\n\nRESULT: " << midpointApprox(a, b, i) << "\n\n\n*****************************************************************\n\n\n";
    
    if(u == 't')
        cout << "\n\nRESULT: " << trapezoidalRule(a, b, i) << "\n\n\n*****************************************************************\n\n\n";
    
    if(u == 's')
        cout << "\n\nRESULT: " << simpsonRule(a, b, i) << "\n\n\n*****************************************************************\n\n\n";
    
    return 0;
}

/**************************************************
 THIS MUST CHANGE FOR DIFFERENT IMPLEMENTATIONS
**************************************************/
float userDefinedFunction(float input) {
    return sqrt(1 + pow(input,3));
}
/**************************************************
**************************************************/


/************************* MIDPOINT APPROXIMATION ******************************
 
 a = start point
 b = end point
 i = # of rectangular approximations
 
 deltaX = (b - a)/i
 
 for a given function, f(x):
 
 i starts at 1
 series: deltaX * ( f( a + (deltaX * (i - 1/2)) ) + ... f( a + (deltaX * (n - 1/2))))
 
 ERROR BOUND FOR MIDPOINT APPROXIMATION
 
 ADD IN LATER
 *******************************************************************************/
float midpointApprox(int a, int b, int i) {
    float deltaX = (float)(b-a)/(float)(i);
    float sum = 0;
    
    for (int j = 1; j <= i; j++) {
        sum += userDefinedFunction(a + deltaX * (j - .5));
    }
    
    sum *= deltaX;
    
    return sum;
}


/************************* TRAPEZOIDAL RULE ************************************
 
 a = start point
 b = end point
 i = # of rectangular approximations
 
 deltaX = (b - a)/i
 
 for a given function, f(x):
 
 i starts at 0
 series: 1/2 * (f( a + (deltaX * i )) + 2f(a + (deltaX * i+1)) + .... + 2f(a + (deltaX * n-1)) + f( a + (deltaX * n)))
 
 ERROR BOUND FOR TRAPEZOIDAL APPROXIMATION
 
 ADD IN LATER
 *******************************************************************************/
float trapezoidalRule(int a, int b, int i) {
    
    float deltaX = (float)(b-a)/(float)(i);
    float sum = 0;
    
    sum = userDefinedFunction(a);
    
    for (int j = 1; j <= i-1; j++) {
        sum += 2 * userDefinedFunction(a + deltaX * j);
    }
    
    sum += userDefinedFunction(a + deltaX * i);
    
    sum *= .5 * deltaX;
    
    return sum;
}


/************************* SIMPSON'S RULE ************************************
 
 a = start point
 b = end point
 i = # of rectangular approximations
 
 deltaX = (b - a)/i
 
 for a given function, f(x):
 
 i starts at 0
 series: 1/3 * deltaX * ( f( a + (deltaX * i )) + 4f(a + (deltaX * i+1)) + 2f(a + (deltaX * n-1)) + ... + 2f(x) + 4f(x) + f( a + (deltaX * n)))
 
 ERROR BOUND FOR TRAPEZOIDAL APPROXIMATION
 
 ADD IN LATER
 *******************************************************************************/
float simpsonRule(int a, int b,  int i) {
    float deltaX = (float)(b-a)/(float)(i);
    float sum = 0;
    
    sum = userDefinedFunction(a);
    
    for (int j = 1; j <= i-1; j++) {
        if (j%2 == 0) {
            sum += 2 * userDefinedFunction(a + deltaX * j);
        }
        else
            sum += 4 * userDefinedFunction(a + deltaX * j);
    }
    
    sum += userDefinedFunction(a + deltaX * i);

    sum *= deltaX;
    sum /= 3;
    
    return sum;
}

void getUserInput(int &a, int &b) {
    int lower = 0;
    int upper = 0;
    bool success = false;
    
    while (!success) {
        cout << "ENTER THE LOWER BOUND FOR INTEGRATION: ";
        cin >> lower;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << "Input invalid." << endl;
        }
        else
            success = true;
    }
    a = lower;
    cout << endl;
    success = false;
    
    while(!success) {
        cout << "ENTER THE UPPER BOUND FOR INTEGRATION: ";
        cin >> upper;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << "Input invalid." << endl;
        }
        else
            success = true;
    }
    b = upper;
    cout << endl;
}

void getApproximation(char &u) {
    char input = 'a';
    bool success = false;
    cout << "------NUMERICAL INTEGRATION TECHNIQUE------\n(M)idpoint Approximation\n(T)rapezoidal Rule\n(S)impson's Rule\nInput: ";
   
    while (!success) {
        cin >> input;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << "Input invalid." << endl;
        }
        else
            success = true;
        
        input = tolower(input);
        
        if (input != 'm' && input != 't' && input != 's') {
            cout << "That choice is invalid." << endl;
            success = false;
        }
        else
            success = true;
    }
    
    u = input;
}

void getNumberSubdivisions(int &i) {
    int sub = 0;
    bool success = false;
    
    while (!success) {
        cout << "ENTER THE NUMBER OF SUBDIVISIONS: ";
        cin >> sub;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << "Input invalid." << endl;
        }
        else
            success = true;
        
        if (sub <= 0) {
            cout << "Enter a valid number of subdivisions.\n";
            success = false;
        }
        else
            success = true;
    }
    i = sub;
    cout << endl;
}
