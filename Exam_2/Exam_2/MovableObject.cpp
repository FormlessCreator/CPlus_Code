#include "MovableObject.h"
#include <iostream>
using namespace std;

MovableObject::MovableObject(int _xposistion, int _yPosition)
{
	// Set the position.
	xPosition = _xposistion;
	yPosition = _yPosition;
}

void MovableObject::Display()
{
	// Print the display.
	cout << "Player is at position: (" << xPosition << ", " << yPosition << ")" << endl;
}

MovableObject::~MovableObject()
{
	// No object needs to be deleted.
	// Print to see if object destructor is called.
	cout << "MovableObject Destructor\n" << endl;
}
