// Gain access to the time functions header.
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/// <summary>
/// This funtion generates a random number.
/// </summary>
/// <param name="numberOfRandoms">
/// The given number dimensions</param>
void generateRandom(int numberOfRandoms)
{
	// Create a random seed using the current
	// time generated as a basis for rand().
	srand(time(NULL));

	// Create a loop to using the parameter
	// input to create the given amount of
	// random input.
	int loop = 0;
	for (loop = 0; loop < numberOfRandoms; ++loop)
	{
		int randomNumber = rand();
		// Print the value of random numbers.
		cout << "The " << loop << " random number "
			"is " << randomNumber << endl;
	}
}

/// <summary>
/// This function prints out a character array
/// in reverse.
/// </summary>
/// <param name="inputString">The entered string.</param>
/// <returns>A character string pointer.</returns>
char* reverseString(char inputString[])
{
	char newString[256] = "";
	int length = strlen(inputString);
	for (int i = 0; i < length; i++)
	{
		char c = inputString[i];
		newString[length - i] = c;
	}
	strcpy_s(inputString, sizeof(inputString), newString);
	return inputString;
}