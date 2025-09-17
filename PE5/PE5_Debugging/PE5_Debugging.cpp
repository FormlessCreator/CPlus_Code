// PE5_Debugging.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    // Call the generate random functions.
    generateRandom(25);

    // Prompt user for string input.
    char input[50] = "";
    cout << "Please enter a word: ";
    cin >> input;

    // Clear all characters in the stream input buffer.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Call the method.
    char* charArrayPointer = reverseString(input);
    
    // This error resulted in a buffer overflow as the copied string characters
    // are more than the specified number of characters that the input can hold.
    // The size it was set to copy was 128 to a destination size of 5.

    // Due to this the input can only hold the null terminator by defualt.

    // The destination string size should be set input size.
    // Like sizeof(inputString);

    cout << charArrayPointer << endl;
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
