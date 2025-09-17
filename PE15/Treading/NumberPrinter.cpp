#include "NumberPrinter.h"
#include <iostream>

using namespace std;

NumberPrinter::NumberPrinter(int _number)
{
	// Set the number.
	number = _number;
}

NumberPrinter::~NumberPrinter()
{
}

void NumberPrinter::Print()
{
	// Print the number 10 times on the same line.
	// Without an endl.
	// Now the loop prints 50 times.
	for (int loop = 0; loop < 50; ++loop)
	{
		// Print:
		// I added the number with the loop to check
		// for disorganization.
		cout << number + loop << " ";
	}
}
