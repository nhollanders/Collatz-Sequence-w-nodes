#include <iostream>
#include <string>

#include "includes/collatzFinder.h"

using namespace std;

int main() 
{
    bool isRunning = true;

    CollatzFinder collatzFinder = CollatzFinder();

    while (isRunning)
    {   
        cout << "Enter a integer less than or 100: ";
        
        string inputPar;
        int number;

        getline(cin, inputPar);

        try
        {
            number = stoi(inputPar);
            if ( number > 100 )
            {
                throw("Input exceeds number limit!");
            }
        }
        catch(...)
        {
            cout << "Invalid input try again!" << endl;
            continue;
        }
        
        collatzFinder.findLongestSequence(number);
        collatzFinder.displayLongestSequence();

        cout << endl << "Would you like to enter another number (y/n)? ";
        getline(cin, inputPar);
        char anwser = inputPar[0];
        if (anwser == 'y')
        {
            continue;
        }
        else
        {
            isRunning = false;
            break;
        }
    }

    return 0;
}