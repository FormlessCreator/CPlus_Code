// Treading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "GamePlay.h"
#include "NumberPrinter.h"
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

int main()
{
    // Create a vector or list of thread pointers.
    vector<thread*> listOfTreadsPointers;

    // Create a for loop that runs 10 times.
    // Now the loop runs 50 times for 50 threads.
    for (int loop = 0; loop < 50; ++loop)
    {
        // Create a new NumberPrinter object.
        NumberPrinter* firstPrint = new NumberPrinter(1);

        // Create a new tread pointer and pass the NewPrinter 
        // object print method as the parameter.
        thread* newThread = new thread(&NumberPrinter::Print, firstPrint);

        // Call its print() method.
        // firstPrint->Print();

        // Push the created new threads into the list.
        listOfTreadsPointers.push_back(newThread);

        //// Delete pointers for memory.
        //delete firstPrint;
        //firstPrint = nullptr;

        //delete newThread;
        //newThread = nullptr;
    }

    // Join all the created threads to the main engine.
    for (int loop = 0; loop < listOfTreadsPointers.size(); ++loop)
    {
        // Join threads.
        listOfTreadsPointers[loop]->join();

        // Delete the thread pointer.
        delete listOfTreadsPointers[loop];

        // Set to nullptr.
        listOfTreadsPointers[loop] = nullptr;
    }

    // [4.a] The output is almost identical as the previous output.
    // [4.b] By my observation, As a result of the light load for
    // printing calculation, it takes almost the same amount of 
    // time for each thread to finish printing the number.

    // [5.a] The first loop numbers appears to be jumbled up. The
    // other loops appear to be organized.
    // I think it is because some treads appear to print out at the
    // same times as others. Gradually due to time diliation with the 
    // number of loop prints it seem to act like a first come first
    // serve basis.

    // Create space.
    cout << "\n" << endl;

    // Create 5 GamePlay objects with unique names.
    GamePlay firstPlay =  GamePlay("Physics");
    GamePlay secondPlay =  GamePlay("KillStreak");
    GamePlay thirdPlay =  GamePlay("One-Shot");
    GamePlay fourthPlay = GamePlay("Healing");
    GamePlay fifthPlay = GamePlay("Reloading");

    // Create vector for thread pointers.
    vector<thread*> listsOfGamePlayThreads;

    // I will use mutex for treads to run by first come, first serve basis.
    mutex gamePlayMutex;

    // Push the objects to the tread pointer by creating new threads.
    listsOfGamePlayThreads.push_back(new thread(&GamePlay::Update, firstPlay, &gamePlayMutex));
    listsOfGamePlayThreads.push_back(new thread(&GamePlay::Update, secondPlay, &gamePlayMutex));
    listsOfGamePlayThreads.push_back(new thread(&GamePlay::Update, thirdPlay, &gamePlayMutex));
    listsOfGamePlayThreads.push_back(new thread(&GamePlay::Update, fourthPlay, &gamePlayMutex));
    listsOfGamePlayThreads.push_back(new thread(&GamePlay::Update, fifthPlay, &gamePlayMutex));

    /* [5] Update complete always appear to be the second to the last item
     * to be printed in many runs.*/
    
    // Use a for loop to join the threads.
    for (int loop = 0; loop < listsOfGamePlayThreads.size(); ++loop)
    {
        // Join the threads.
        listsOfGamePlayThreads[loop]->join();

        // Delete the pointer and set to nullptr;
        delete listsOfGamePlayThreads[loop];
        listsOfGamePlayThreads[loop] = nullptr;
    }

    // Print Update Complete, time to draw!
    cout << "Update Complete! Time to Draw." << endl;
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
