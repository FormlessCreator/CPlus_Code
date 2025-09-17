// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
#include "Player.h"
#include <crtdbg.h> 
#include "Fighter.h"
using namespace std;

int main()
{
    // Create a fighter on a heap using the defualt constructor.
    Fighter* firstFighter = new Fighter();

    // Create the second fighter using the parameterized constructor.
    Fighter* secondFighter = new Fighter("The Chef", "Cleaver", 15, 16, 20, 25);

    // Print both fighter out.
    firstFighter->printFighter();
    secondFighter->printFighter();

    // Delete the pointers.
    delete firstFighter;
    delete secondFighter;

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
