// PE6_Pointers.cpp : This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    // Create an interger and set to 10.
    int myInteger = 10;

    // Create an interger pointer to point to myInterger address.
    int* myIntPointer = &myInteger;

    // Derefernce the pointer and use it to store 20.
    *myIntPointer = 20;

    // Print value.
    cout << "Value stored in myInteger is " << myInteger << endl;

    // Call the first function.
    // Print and comment.
    passByValue(myInteger);
    cout << "Value stored in myInteger is: " << myInteger << endl;

    // The integer did not change from 20 to 30 as it tried to
    // change the value of my interger directly without accessing 
    // the reference or the memory address to the my integer value.
    // This can't happen in a function directly as the complier
    // do not know where to refer to value in the function.

    // Call the second function.
    // And print.
    passByReference(myInteger);
    cout << "Value stored in myInteger is: " << myInteger << endl;

    // The integer changed from 20 to 40 as the reference of the
    // myinteger was accessed directly and set to the new value.

    // The third value.
    // And print.
    passByPointer(myIntPointer);
    cout << "Value stored in myInteger is: " << myInteger << endl;

    // The integer changed from 40 to 50 as the pointer that holds
    // the memory address of the my interger value is accessed and
    // its value is changed through dereferencing.
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
