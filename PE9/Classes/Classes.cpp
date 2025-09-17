// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
#include "Player.h"
#include <crtdbg.h> 

int main()
{
    // Create player using defualt constructor on the stack.
    Player stackPlayer = Player();

    // Create a char* for name.
    char* name = new char[15] 
        {'T', 'h', 'e', ' ', 'E', 'n', 'g', 'r', 'a', 'v', 'e', 'r'};


    // Create player using parameterized constructor on the stack.
    Player stackPlayer2 = Player(name, 12, 10, 15, 9);

    // Create player class using defualt counstructor on the heap.
    Player* playerHeap = new Player();

    // Create player class using paramiterized constructor on the heap.
    Player* playerHeap2 = new Player(name, 20, 8, 10, 7);

    // Print all the player's on the stack out.
    stackPlayer.PrintPlayer();
    stackPlayer2.PrintPlayer();

    // Print all the player's pointers out.
    playerHeap->PrintPlayer();
    playerHeap2->PrintPlayer();

    // Delete the name pointer;
    delete[] name;
    name = nullptr;
    
    // Delete the player pointers.
    delete playerHeap;

    delete playerHeap2;

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
