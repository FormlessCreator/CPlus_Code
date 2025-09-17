// More_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    // Create variable with initial value.
    int number = 10;

    // Print data in variable.
    cout << "The value of number is " << number << "\n"
        << endl;

    // Call the change variable.
    changeVariable(number);

    // Print number value again.
    cout << "The value of number is " << number << "\n"
        << endl;

    // Call change pointer method using number address.
    changePointer(&number);

    // Print again.
    cout << "The value of number is " << number << "\n"
        << endl;

    // With the pointer, one can easily alter the memory
    // of the pointer by deferencing the value address.
    // This however does not work with direct value changes.

    // Create an array of integers.
    int array[8] = { 1,2,3,4,5,6,7,-1 };

    // Create new integer pointer.
    // The int pointer takes the address of the first
    // element by defualt in the array.
    // Has the whole array in memory but uses only the
    // first address as a pointer.
    int* intPointer = array;

    // Print out the number using the getLenghtArray.
    int arrayLenght = getLenghtArray(intPointer);

    // Print lenght.
    cout << "The lenght of the array is " << arrayLenght
        << "\n" << endl;

    // Call getLenghtPoint and pass in array pointer.
    int pointerLenght = getLenghtPointer(intPointer);

    // Print the pointer lenght.
    cout << "The pointer lenght is " << pointerLenght
        << "\n" << endl;

    // Create separate pointers for each funtion call.
    int* firstStackPointer;
    int* secondHeapPointer;

    // Call and save pointers addresses.
    firstStackPointer = createStackArray();
    secondHeapPointer = createHeapArray(5);

    // Print out the contents of arrays.
    cout << "Stack array elements: " << endl;
    for (int loop = 0; loop < 5; ++loop)
    {
        // Print out pointer contents.
        cout << firstStackPointer[loop] << ", " << endl;
    }

    // Print out the contents of arrays.
    cout << "\nHeap array elements: " << endl;
    for (int loop = 0; loop < 5; ++loop)
    {
        // Print out pointer contents.
        cout << secondHeapPointer[loop] << endl;
    }

    // Delete the heap array.
    delete[] secondHeapPointer;

    // Comments:
    // The stack pointer returns random memory numbers as the
    // array values do not exist or can be accessed after the
    // stack function ends as pointer is returned anything 
    // related to stack is remove from memory compared to
    // the heap funtion as values are stored on heap.
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
