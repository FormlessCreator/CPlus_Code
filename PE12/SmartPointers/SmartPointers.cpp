// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include "GameLevel.h"
#include <string>
#include <vector>
#include <iostream>
//#include <memory>
using namespace std;

void WrapperWithNormalPointer()
{
    // Create a treasure vector list.
    vector<string> levelItems1 = vector<string>{ "Ring of Truth", "Dagger of Grace" };

    // Create a normal pointer that hold the game level class.
    GameLevel* level1 = new GameLevel("Ceiling", 1, levelItems1, 10);
}

void WrapperWithSmartPointer()
{
    // Create a treasure vector list.
    vector<string> levelItems2 = vector<string>{ "Mask of Lies", "Dagger of Stealth", "Eye of Despair"};

    // Create a unique smart pointer that hold the game level class.
    unique_ptr<GameLevel> level2 = make_unique<GameLevel>(GameLevel("Hidden Door", 2, levelItems2, 25));
}

int main()
{
    // Call the smart pointer wrapper function.
    WrapperWithSmartPointer();

    // Check for leaks for the smart pointer.
    if (_CrtDumpMemoryLeaks())
    {
        // Print message for memory leaks for smart pointer.
        cout << "There is a memory leak for smart pointer!\n" << endl;
    }
    else
    {
        // Print message for memory leaks for smart pointer.
        cout << "There is no memory leak for smart pointer!\n" << endl;
    }

    // Call the normal pointer wrapper function.
    WrapperWithNormalPointer();

    // Check for leaks for the normal pointer.
    if (_CrtDumpMemoryLeaks())
    {
        // Print message for memory leaks for normal pointer.
        cout << "\nThere is a memory leak for normal pointer!\n" << endl;
    }
    else
    {
        // Print message for memory leaks for normal pointer.
        cout << "\nThere is no memory leak for normal pointer\n!" << endl;
    }
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
