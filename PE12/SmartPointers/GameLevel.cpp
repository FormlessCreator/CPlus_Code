#include "GameLevel.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

GameLevel::GameLevel()
	:GameLevel("Level 0", 0, {"Empty"}, 0)
{

}

GameLevel::GameLevel(std::string _exitLocation, int _levelNumber, std::vector<std::string> _treasures, int _enemies)
{
	// Set values.
	exitLocation = _exitLocation;
	levelNumber = _levelNumber;
	treasures = _treasures;
	enemies = _enemies;

	// Print the values.
	cout << "\nThe counstructor is called!\n" << endl;

	cout << "Exit location: [ " << exitLocation << " ]" << endl;
	cout << "Level Number: [ " << levelNumber << " ]" << endl;
	cout << "Number of Enemies: [ " << levelNumber << " ]" << endl;
	cout << "Hidden treasures: " << endl;

	// Print out the vector list treasure contents.
	for (int loop = 0; loop < treasures.size(); ++loop)
	{
		cout << "\t-> [ " << treasures[loop] << " ]" << endl;
	}
}

GameLevel::~GameLevel()
{
	// Print that the deconstructor is called.
	cout << "\nThe Deconstructor is called!\n" << "Game level is deleted!\n" << endl;
}
