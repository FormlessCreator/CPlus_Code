#include <iostream>
#include "functions.h"
using namespace std;

void passByValue(int xValue)
{
	// Set the xValue to 30.
	xValue = 30;
}

void passByReference(int& xReference)
{
	// Set reference or address to 40;
	xReference = 40;
}

void passByPointer(int* xPointer)
{
	// Set the pointer to 50 by dereferencing.
	*xPointer = 50;
}