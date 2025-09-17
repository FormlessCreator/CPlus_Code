// Exam_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Mayowa Famade.
// Section: IGME 209.01
// Exam: Exam 2.

#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <memory>
#include "MovableObject.h"
#include "Player.h"
using namespace std;

void Wrapper()
{
	// Create unique smart pointers for 2 movable object and 3 players pointers.
	// Objects:
	shared_ptr<MovableObject*> object1 = make_shared<MovableObject*>
		(new MovableObject(RandomNumber(-100, 100), RandomNumber(-100, 100)));
	shared_ptr<MovableObject*> object2 = make_shared<MovableObject*>
		(new MovableObject(RandomNumber(-100, 100), RandomNumber(-100, 100)));

	// Players:
	shared_ptr<Player*> Player1 = make_shared<Player*>
		(new Player(RandomNumber(-100, 100), RandomNumber(-100, 100)));
	shared_ptr<Player*> Player2 = make_shared<Player*>
		(new Player(RandomNumber(-100, 100), RandomNumber(-100, 100)));
	shared_ptr<Player*> Player3 = make_shared<Player*>
		(new Player(RandomNumber(-100, 100), RandomNumber(-100, 100)));

	// Create a vector 
	vector <unique_ptr <MovableObject>> population;

	// Push the pointers into the vector list.
	population.push_back(*object1);
	population->push_back(*object2);
	population->push_back(*Player1);
	population->push_back(*Player2);
	population->push_back(*Player3);

	// Use a for loop to print display for all objects.
	for (int loop = 0; loop < population->size(); ++loop)
	{
		// Call the display for all object.
		(*population)[loop].Display();
	}
}

int main()
{
	// Create a randomize seed with time.
	srand(time(nullptr));

	//
	// Check if there is not memory leaks.
	if (!_CrtDumpMemoryLeaks())
	{
		// Print no memory leaks.
		cout << "No Memory Leaks" << endl;
	}
}

/// <summary>
/// Create a random number
/// </summary>
/// <param name="max">The max number</param>
/// <param name="min">The min number</param>
/// <returns></returns>
int RandomNumber(int max, int min)
{
	float percent = rand() / RAND_MAX;
	float difference = max - min;
	float randomNumber = percent * difference + min;

	// Return the number.
	return randomNumber;
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
