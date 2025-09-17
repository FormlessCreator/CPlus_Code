#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int _xPosition, int _yposition)
	: MovableObject(_xPosition, yPosition)
{
	// Set the size and inventory as defualt.
	size = 3;
	inventoryIds = new int[size] {3, 9, 12};
}

void Player::Display()
{
	// Call the object position.
	MovableObject::Display();

	// Print out the inventory.
	cout << "The inventory contains: " << endl;

	// Use a for loop to print inventory.
	for (int loop = 0; loop < size; ++loop)
	{
		cout << inventoryIds[loop] << ", " << endl;
	}
}

Player::~Player()
{
	// Delete the inventoryIds.
	delete inventoryIds;

	// Print to see if object destructor is called.
	cout << "Player Destructor\n" << endl;
}
