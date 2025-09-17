#include <iostream>
#include "Functions.h"
using namespace std;

// Define the functions.

/// <summary>
/// This method prints out the value of integer number.
/// </summary>
/// <param name="number">The int value</param>
void changeVariable(int number)
{
	// Alter the value of function.
	int x = number;

	// Print value.
	cout << "Number Value is now " << x << endl;
}

/// <summary>
/// This takes in a pointer and alter the value of the
/// pointer.
/// </summary>
/// <param name="newPointer">An int pointer</param>
void changePointer(int *newPointer)
{
	// Deference pointer and alter data.
	*newPointer = *newPointer + 10;

	// Print message.
	cout << "Value at pointer is " << *newPointer <<
		endl;
}

/// <summary>
/// This returns the lenght of an array.
/// </summary>
/// <param name="array">The given array</param>
/// <returns>An integer</returns>
int getLenghtArray(int array[])
{
	// Create a loop to keep track.
	int i = 0;
	int count = 0;

	// Use a while loop to find the lenght of the array
	// until it hits the terminator.
	while (array[i] != -1)
	{
		// Increase count by one.
		count += 1;

		// Add 1 to i.
		i += 1;
	}

	// Return the count.
	return count;
}

/// <summary>
/// This gets the lenght of an array using the pointer 
/// to the array.
/// </summary>
/// <param name="intPrt">The array pointer.</param>
/// <returns>An int</returns>
int getLenghtPointer(int* intPrt)
{
	// Create count to keep track of loops.
	int count = 0;

	// Use while loop to move though pointer addresses.
	// Dereference the first pointer element address
	// for address value.
	while (*intPrt != -1)
	{
		// Increase count by 1.
		count++;

		// Use pointer Arithmetic to move unto the next
		// pointer address.
		intPrt++;
	}

	// Return the count.
	return count;
}

/// <summary>
/// This function returns an int pointer.
/// </summary>
/// <returns>An int pointer</returns>
int* createStackArray()
{
	// Create an int array size of 5.
	int intArray[5];

	// Use for loop for data placement.
	for (int loop = 0; loop < 5; ++loop)
	{
		// Set data to loop index.
		intArray[loop] = loop;
	}

	// Return the array as a pointer.
	return intArray;
}

/// <summary>
/// This funtion creates an array of defined size
/// on the heap. 
/// </summary>
/// <param name="sizeOfArray">The array size</param>
/// <returns>An int pointer</returns>
int* createHeapArray(int sizeOfArray)
{
	// Create an array on heap using the new key word
	// and an int pointer.
	// To make a memory on heap you need pointer to
	// access memory.
	int* intArray = new int[sizeOfArray];

	// Fill array with data using for loop.
	for (int loop = 0; loop < sizeOfArray; ++loop)
	{
		// Add data to pointer memory.
		intArray[loop] = loop;
	}

	// Return the pointer.
	return intArray;
}