// Templated Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Stack.h"
using namespace std;

int main()
{
	// Create 3 stacks of different data types.
	Stack<int> intStack;
	Stack<float> floatStack;
	Stack<string> stringStack;

	// Push elements to the stacks.
	cout << "Add elements to 3 different stack:" << endl;
	intStack.Push(10);
	intStack.Push(20);
	intStack.Push(30);
	intStack.Push(40);

	floatStack.Push(112.123f);
	floatStack.Push(123.123f);
	floatStack.Push(152.567f);
	floatStack.Push(173.987f);

	stringStack.Push("I");
	stringStack.Push("am");
	stringStack.Push("testing");
	stringStack.Push("this");
	stringStack.Push("code");

	// Print the stack contents.
	intStack.Print();
	floatStack.Print();
	stringStack.Print();

	// Pop elements:
	cout << "\nPop the last elements:" << endl;
	intStack.Pop();
	floatStack.Pop();
	stringStack.Pop();

	// Print the stack contents.
	intStack.Print();
	floatStack.Print();
	stringStack.Print();

	// Pop again elements:
	cout << "\nPop the last elements again:" << endl;
	intStack.Pop();
	floatStack.Pop();
	stringStack.Pop();

	// Print the stack contents.
	intStack.Print();
	floatStack.Print();
	stringStack.Print();

	// Push elements to the stacks again.
	cout << "\nAdd elements to 3 different stack again:" << endl;
	intStack.Push(50);
	floatStack.Push(111.111f);
	stringStack.Push("stack");

	// Print the stack contents.
	intStack.Print();
	floatStack.Print();
	stringStack.Print();

	// Get the last elements using Top().
	cout << "\nGet the last elements using Top():" << endl;
	int intTop = intStack.Top();
	float floatTop = floatStack.Top();
	string stringTop = stringStack.Top();

	// Print the stack contents.
	cout << intTop << endl;
	cout << floatTop << endl;
	cout << stringTop << endl;

	// Create a new stack and copy using copy constructor.
	Stack<int> copy1Stack(intStack);
	Stack<float> copy2Stack(floatStack);
	Stack<string> copy3Stack(stringStack);

	// Print the stack contents.
	cout << "\nCopy stacks using the copy constructor:" << endl;
	copy1Stack.Print();
	copy2Stack.Print();
	copy3Stack.Print();

	// Pop again elements:
	cout << "\nPop the last elements of copied stacks:" << endl;
	copy1Stack.Pop();
	copy2Stack.Pop();
	copy3Stack.Pop();

	// Print the stack contents.
	cout << "\nPrint after popping stacks using the copy constructor:" << endl;
	copy1Stack.Print();
	copy2Stack.Print();
	copy3Stack.Print();

	// Set to original and copy using copy assignment.
	intStack = copy1Stack;
	floatStack = copy2Stack;
	stringStack= copy3Stack;

	// Print the stack contents.
	cout << "\nPrint original after using the copy assignment operator:" << endl;
	intStack.Print();
	floatStack.Print();
	stringStack.Print();

	// Dump memory leaks.
	_CrtDumpMemoryLeaks();
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
