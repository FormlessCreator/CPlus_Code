// Theater.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.


#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
    // Assign a number of seats.
    int numberOfSeats = 20;

    // Call the iterate function for number of seats and save in variable.
    unsigned int loopResults = Iteration(numberOfSeats);

    // Call the iterate function for number of seats and save in variable.
    unsigned int recursionResults = Recursion(numberOfSeats);

    // Call the iterate function for number of seats and save in variable.
    unsigned int formulaResults = Formula(numberOfSeats);

    // Print out the results.
    cout << "The number of hands using Iteration: " << loopResults << endl;
    cout << "The number of hands using Recursion: " << loopResults << endl;
    cout << "The number of hands using Formula: " << loopResults << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
