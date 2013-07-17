//  Skeleton of program to calculate the final score of a competitor
//  For use in lab exercise
//  Programmed by: Dr. Monisha Pulimood

//  ** Modify the maintenance documentation as appropriate ***
// Name: *** Put your name here
// Course: 
// Semester: 
// Instructor: Dr. Pulimood
// 
// Description: *** put a brief description of the program here
// Filename: scoreDriver.cpp
// Last modified on: September 18, 2012


#include <iostream>
#include <cmath>
#include "scoreFunctions.h"
// include header file here

using namespace std;

int main(void)
{
	float degree, finalScore;
	int numJudges;
	float scores [MAXNUM];
	bool success = true, valid = true;
	bool done = false;
	char choice; 

	while (!done)
	{
		do 
		{
			cout << "Input the degree of difficulty for this event (between 1.2 and 3.8): ";
			degree = getValidFloat();
			if ((degree < 1.2) || (degree > 3.8))
			{
				valid = false;
				cout << "The degree of difficulty is invalid. Please try again." << endl;
			}
			else 
				valid = true;
		} while (!valid);
		
		
		// *** DO: insert code to enable user to input valid number of judges
			
		

		cout << "Input the scores given by each judge (between 0 and 10): ";
		for (int i = 0; i < numJudges; i++)
		{
			do
			{
				scores[i] = getValidFloat();
				if ((scores[i] < 0) || (scores[i] > 10))
				{
					valid = false;
					cout << "The score is invalid. Please try again." << endl;
				}
				else 
					valid = true;
			} while (!valid);
		}
		
		// *** Call the function calcFinalScore () here ***

		
		if (success) 
			cout << "The final score for the competitor is " << finalScore << endl;
		else
			cout << "Sorry! Could not calculate the final score." << endl << endl;
		cout << "Do you want to continue? Type Y or N : ";
		cin >> choice;
		if (tolower(choice) == 'y')
			done = false;
		else 
			done = true;
	}
	
	cout << "Exiting program." << endl << endl; 
	return 0;
	
}

