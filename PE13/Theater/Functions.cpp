#include "Functions.h"
#include <iostream>;

using namespace std;

/// <summary>
/// This calculate the number of hands in a row using a for loop iteration.
/// </summary>
/// <param name="numberOfSeats">The given number of seats in a row.</param>
/// <returns>An unsigned int</returns>
unsigned int Iteration(int numberOfSeats)
{
	// Fields:
	unsigned int numberOfHands = 0;

	// Create a for loop using the number of steps.
	for (int loop = 0; loop < numberOfSeats; ++loop)
	{
		// Check if the seat at loop is even.
		if (loop % 2 == 0)
		{
			// Increase the hands count by 4 hands.
			numberOfHands += 4;
		}
		else
		{
			// Increse the hand count by 3.
			numberOfHands += 3;
		}
	}

	// Return the number of hands.
	return numberOfHands;
}

/// <summary>
/// This calculate the number of hands in a row using a recursive method.
/// </summary>
/// <param name="numberOfSeats">The given number of seats in a row.</param>
/// <returns>An unsigned int</returns>
unsigned int Recursion(int numberOfSeats)
{
	// Create a base case that returns 0 if the number of seats is 0.
	if (numberOfSeats <= 0)
	{
		// Return 0 to the function.
		return 0;
	}

	// Else if the number of seat is even.
	if (numberOfSeats % 2 == 0)
	{
		// Call a this function again using recursion and add 4 to it.
		// Use return for recursion and subtract the seat by 1.
		return Recursion(--numberOfSeats) + 4;
	}
	else
	{
		// Call a this function again using recursion and add 3 to it.
		// Use return for recursion and subtract the seat by 1.
		return Recursion(--numberOfSeats) + 3;
	}
}


/// <summary>
/// This calculate the number of hands in a row using a formular.
/// </summary>
/// <param name="numberOfSeats">The given number of seats in a row.</param>
/// <returns>An unsigned int</returns>
unsigned int Formula(int numberOfSeats)
{
	// Fields:
	unsigned int totalNumberOfHands = 0;
	unsigned int evenHands = 4;
	unsigned int oddHands = 3;

	// Find the number of even seats in the row using the number of seats.
	// Using the division truncation for rounding down decimal numbers.
	unsigned int numberOfEvenSeats = numberOfSeats / 2;

	// Find the number of odd seats in the row using the number of seats.
	// By number of even seats and check if there is a remainder of 1.
	// In an odd number, odd number is always total even numbers plus 1.
	unsigned int numberOfOddSeats = (numberOfEvenSeats) + 1;

	// Find the total number of hands in even seats.
	unsigned int totalHandsInEvenSeats =
		numberOfEvenSeats * evenHands;

	// Find the total number of hands in odd seats.
	unsigned int totalHandsInOddSeats =
		numberOfOddSeats * evenHands;

	// Find the total number of hands by summing all the even and odd hands.
	totalNumberOfHands = totalHandsInEvenSeats + totalHandsInOddSeats;

	// Return the total number of hands.
	return totalNumberOfHands;
}
