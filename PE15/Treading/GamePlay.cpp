#include "GamePlay.h"
#include <iostream>
#include <string>
#include <mutex>

using namespace std;

GamePlay::GamePlay(std::string _name)
{
	// Set the name.
	name = _name;
}

GamePlay::~GamePlay()
{
}

void GamePlay::Update(mutex* mutexPointer)
{
	// Lock the process.
	mutexPointer->lock();

	// Print the name and percentage message.
	// 10 times on a single line.
	for (int loop = 0; loop < 10; ++loop)
	{
		cout << name << ": " << (loop + 1) * 10 << "% Complete" << endl;
	}

	// Create space.
	cout << "\n" << endl;

	// Unlock the process after the loop is done.
	mutexPointer->unlock();
}
