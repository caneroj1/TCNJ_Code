//
//  TermDriver.cpp
//  
//
//  Created by Joseph Canero on 10/8/12.
//
//

#include <iostream>
#include "Term.cpp"

using namespace std;

int main(void)
{
    Term t1(3, 5);
    Term t2(199, 5);
    Term t3(1,1);
    
    cout << "Term 1 is: " << endl;
    t1.displayTerm();
    cout << "Term 2 is: " << endl;
    t2.displayTerm();
    cout << "Term 3 is: " << endl;
    t3.displayTerm();
    
    t3 = t1+t2;
    
    cout << "Term 3 after adding Term 1 and Term 2 and storing the value in Term 3 is: " << endl;
    t3.displayTerm();
    
    cout << endl << endl;
    
    Term t4(0, 0);
    
    t4 = t4.inputTerm();
    cout << "Term 4 is: " << endl;
    t4.displayTerm();
    
    Term t5 = t1*t4;
    cout << "Term 5 is: " << endl;
    t5.displayTerm();
    
    Term t6(5);
    t6.inputTerm();
    cout << "Term 6 is: " << endl;
    t6.displayTerm();
    int b = t6.evalTerm();
    cout << "After evaluating Term 6, the result is: " << b << endl;
    
    return 0;
}