// Exam_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    int input;
    float floatInput;

    // Ask player the number of scores.
    cout << "Please enter number of scores: " << endl;
    cin >> input;
   
    // Create pointer.
    float* scoresRead = new float[input];

    // Ask user for number using for loop and assign to pointer.
    for (int loop = 0; loop < input; ++loop)
    {
        cout << "Please enter a score: " << endl;
        cin >> floatInput;
        scoresRead[loop] = floatInput;
    }

    // Call both methods.
    AverageScore(scoresRead, input);
    HighScore(scoresRead, input);

    // Clear memory.
    delete scoresRead;
    scoresRead = nullptr;

    // Clear memory leaks.
    _CrtDumpMemoryLeaks();
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
