//  I made this program to save some time when converting between different number systems.
//
//  numberConverter.cpp
//
//  Created by Joseph Canero on 9/1/13.
//
//

#include "numberConverter.h"

int main() {
    
    //This program will ask the user for three inputs: what base one is starting with (2-10, 16), what base one is converting to,
    //and the number to be converted
    
    //treat the numbers as strings so the digit places can be handled somewhat more easily than with numbers, additionally, real
    //number functionality might be easier to implement with strings.
    
    //since the program will be using strings, there will need to be string parsing and conversion to and from numbers and chars
    //first, let's handle the user input in a loop: do-while
    
    do {
        cout << "\n\nThis program will convert a number in one user-specified number system to another user-specified number system.\nValid number systems range from binary (2) to hexadecimal (16). Please enter only numbers.\n\n";
        //check the user input to make sure it is valid
        checkUserNumberSystem(originalBase, 1); //check to see if each of the bases input are valid
        checkUserNumberSystem(newBase, 2);
        
        //are the two number systems equal?
        if (originalBase == newBase) { 
            cout << "\n\n************ The two number systems are identical! There is no conversion necessary. ************\n\n";
        }
        
        //the input up to this point has been good. now ask user for the number to be converted.
        else {
            cout << "What is the number in base " << originalBase << " that will be converted to base " << newBase << "?\n-> ";
            cin >> number;
            if(numberIsValid(number, originalBase)) { //check if the number contains all valid digits
                int decimalCount = numberHasDecimal(number); //does the number have a full stop indicating a fraction?
                if(decimalCount == 0) {
                    
                    //the number is a whole number
                    //need a variable to store the number as it is being divided, need to use modulo division to determine if there is
                    //a remainder, if there is a remainder that times the base will be the digit at the position of i.
                    //the string needs to be output in reverse
                    
                    int remainder;
                    double result = convertStringToDecInt(number, originalBase); //convert the strinh
                    string res = "";
                    do {
                        //to convert the number into the new base, repeated division by the new base must occur
                        //no remainder, digit is 0
                        if((int)result%(int)newBase == 0) {
                            res += "0";
                            result = result/(int)newBase;
                        }
                        //there is a remainder
                        else {
                            remainder = (int)result%(int)newBase;
                            switch (remainder) {
                                case 1:
                                    res += "1";
                                    break;
                                    
                                case 2:
                                    res += "2";
                                    break;
                                    
                                case 3:
                                    res += "3";
                                    break;
                                    
                                case 4:
                                    res += "4";
                                    break;
                                    
                                case 5:
                                    res += "5";
                                    break;
                                    
                                case 6:
                                    res += "6";
                                    break;
                                    
                                case 7:
                                    res += "7";
                                    break;
                                    
                                case 8:
                                    res += "8";
                                    break;
                                    
                                case 9:
                                    res += "9";
                                    break;
                                    
                                case 10:
                                    res += "A";
                                    break;
                                    
                                case 11:
                                    res += "B";
                                    break;
                                    
                                case 12:
                                    res += "C";
                                    break;
                                    
                                case 13:
                                    res += "D";
                                    break;
                                    
                                case 14:
                                    res += "E";
                                    break;
                                    
                                case 15:
                                    res += "F";
                                    break;
                                    
                                default:
                                    break;
                            }
                            result = result/(int)newBase;
                        }
                    } while (result >= 1.0);
                    cout << "RESULT\n-> ";
                    for (int i = res.length() - 1; i >= 0; i--) {
                        cout << res[i];
                    }
                }
                else if(decimalCount == 1) { //TO BE IMPLEMENTED
                    //the number is a real number with a fractional component
                    //......
                }
                else if(decimalCount > 1) {
                    //the number is invalid because it contains two o more full stops ( "." )
                    cout << "The number you have entered is invalid. It contains more than 1 full stop\n";
                }
            }
        }
        checkUserInput(userIn);
    } while (userIn == 'y' || userIn == 'Y');
    return 0;
}


//check if the user's input is a valid yes or no
void checkUserInput(char &userIn) {
    bool success = false;
    while(!success) {
        cout << "\n\nDo you want to continue converting numbers? (y/n)\n-> ";
        cin >> userIn;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << "************ That input is invalid. Please reenter (y/n). ************\n";
        }
        else {
            if(userIn == 'y' || userIn == 'Y'|| userIn == 'n' || userIn == 'N') {
                success = true;
                cout << "\n";
            }
            else {
                cerr << "************ That input is invalid. Please reenter (y/n) ************\n";
            }
        }
    }
}

//check if the user's input is a number in the valid range of 2-16, inclusive
void checkUserNumberSystem(double &system, int indicator) {
    bool success = false;
    while(!success) {
        if(indicator == 1) {
            cout << "What is the base of the starting number system?\n-> ";
        }
        else {
            cout << "What is the base of the ending number system?\n-> ";
        }
        cin >> system;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cerr << "************ That input is invalid. Please reenter a number system whose base is within the range of 2 - 16, inclusive. ************\n";
        }
        else {
            if(system < 2 || system > 16) {
                cerr << "************ That input is invalid. Please reenter a number system whose base is within the range of 2 - 16, inclusive. ************\n";
            }
            else {
                success = true;
                cout << "\n";
            }
        }
    }
}

//determine if the number that the user inputs is valid with respect to the chosen original base
bool numberIsValid(string number, int base) {
    //bases lower than 10 (inclusive) should not have letters, and negative numbers are not being accepted now
    if(base <= 10) {
        for(int i = 0; i < number.length(); i++) {
            int digit = number[i] - '0';
            if(digit == -3) {
                cout << "Negative numbers are not accepted right now.\n";
                return false;
            }
            else {
                if (digit >= base) {
                    cout << "This number contains an invalid digit!\nThe \"" << digit << "\" is invalid.\n";
                    return false;
                }
            }
        }
        return true;
    }
    //if the base is higher than decimal and less than or equal to hexadecimal
    else if(base > 10 && base <= 16) {
        bool result = true;
        for(int i = 0; i < number.length(); i++) {
            int digit = number[i] - '0';
            //this switch statement will determine if the characters the user inputs are within the valid range of the user's chosen base
            switch (base) {
                case 10:
                    if((digit < 48 && digit >= 32) || (digit < 65 && digit > 57) || digit > 65) {
                        result = false;
                    }
                    break;
                    
                case 11:
                    if((digit < 48 && digit >= 32) || (digit < 66 && digit > 57) || digit > 66) {
                        result = false;
                    }
                    break;
                    
                case 12:
                    if((digit < 48 && digit >= 32) || (digit < 67 && digit > 57) || digit > 67) {
                        result = false;
                    }
                    break;
                    
                case 13:
                    if((digit < 48 && digit >= 32) || (digit < 68 && digit > 57) || digit > 68) {
                        result = false;
                    }
                    break;
                    
                case 14:
                    if((digit < 48 && digit >= 32) || (digit < 69 && digit > 57) || digit > 69) {
                        result = false;
                    }
                    break;
                    
                case 15:
                    if((digit < 48 && digit >= 32) || (digit < 70 && digit > 57) || digit > 70) {
                        result = false;
                    }
                    break;
                    
                case 16:
                    if((digit < 48 && digit >= 32) || (digit < 71 && digit > 57) || digit > 71) {
                        result = false;
                    }
                    break;
            }
            if (!result) {
                cout << "This number contains an invalid digit!\nThe \"" << digit << "\" is invalid.\n";
                return result;
            }
            else if (result) {
                return result;
            }
        }
    }
}

//check if the number the user inputted contains a full stop, indicating there is a fractional component
int numberHasDecimal(string number) {
    int decimalCount = 0;
    for(int i = 0; i < number.length(); i++) {
        char digit = number[i];
        if(digit == '.') {
            decimalCount++;
        }
    }
    return decimalCount;
}

//converts the user's input string into a decimal number depending on the base the user has chosen
double convertStringToDecInt(string number, double base) {
    double result;
    for (int i = number.length() - 1; i >= 0; i--) {
        if(number[i] < 65) {
            double power = pow((double)base, (double)(number.length() - (i + 1)));
            int digit = (number[i] - '0');
            result += power * digit;
        }
        else if(number[i] >= 65) {
            double power = pow((double)base, (double)(number.length() - (i + 1)));
            int digit = (number[i] - '7');
            result += power * digit;
        }
    }
    return result;
}









