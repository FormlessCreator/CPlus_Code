#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>

class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator=(const Stack<T>& other);
    void Push(const T& data);
    T& Top();
    void Pop();
    void Print();
    int Getsize();
    bool IsEmpty();

    // Variables:
    int* arraySize;
    int* stackSize;
    T* itemArray;
};

template<class T>
inline Stack<T>::Stack()
{
    // Intiialize the fields:
    arraySize = new int(2);
    stackSize = new int(0);

    // Create a new array size for the T item array by derefrencing.
    itemArray = new T[*arraySize];
}

template<class T>
inline Stack<T>::~Stack()
{
    // Delete the items on the heap.
    delete arraySize;
    delete stackSize;
    delete[] itemArray;
}

/// <summary>
/// This is the Copy constructor for the stack class.
/// </summary>
/// <typeparam name="T">The generic datatype.</typeparam>
/// <param name="other">The copied stack class data.</param>
template<class T>
inline Stack<T>::Stack(const Stack<T>& other)
{
    /* Check if all the memory for the variables are not null and
     * delete memory and set pointer to nullptr.*/

    if (arraySize != nullptr)
    {
        delete arraySize;
        arraySize = nullptr;
    }

    if (stackSize != nullptr)
    {
        delete stackSize;
        stackSize = nullptr;
    }

    if (itemArray != nullptr)
    {
        delete[] itemArray;
        itemArray = nullptr;
    }

    /* Get the other array size and stack size of other stack and
     * set it to this stack by dereferencing. */
    arraySize = new int(*other.arraySize);
    stackSize = new int(*other.stackSize);

    // Set a new size for the item array.
    itemArray = new T[*arraySize];

    // Use for loop to add the items of the other stack.
    for (int loop = 0; loop < *stackSize; ++loop)
    {
        // Use the loop to add items to the items array.
        itemArray[loop] = other.itemArray[loop];
    }
}

/// <summary>
/// This is the Copy Assignment Operator for the stack class.
/// </summary>
/// <typeparam name="T">The generic datatype.</typeparam>
/// <param name="other">The copied stack class.</param>
/// <returns>The dereferenced stack class data.</returns>
template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    // Check if the other stack is the same as this stack.
    if (this == &other)
    {
        // If it's the same return this stack data and end function.
        return *this;
    }

    // Else:
    /* Check if all the memory for the variables are not null and
     * delete memory and set pointer to nullptr.*/

    if (arraySize != nullptr)
    {
        delete arraySize;
        arraySize = nullptr;
    }

    if (stackSize != nullptr)
    {
        delete stackSize;
        stackSize = nullptr;
    }

    if (itemArray != nullptr)
    {
        delete[] itemArray;
        itemArray = nullptr;
    }

    /* Get the other array size and stack size of other stack and
     * set it to this stack by dereferencing. */
    arraySize = new int(*other.arraySize);
    stackSize = new int(*other.stackSize);

    // Set a new size for the item array.
    itemArray = new T[*arraySize];

    // Use for loop to add the items of the other stack.
    for (int loop = 0; loop < *stackSize; ++loop)
    {
        // Use the loop to add items to the items array.
        itemArray[loop] = other.itemArray[loop];
    }

    // Return this stack data.
    return *this;
}

/// <summary>
/// This adds a data to the list of items in the item array.
/// </summary>
/// <typeparam name="T">The generic data type.</typeparam>
/// <param name="data">The added data.</param>
template<class T>
inline void Stack<T>::Push(const T& data)
{
    // Field(if needed):
    int* newArraySize;

    // Check if the array size is less or equal to the stack size.
    if (*arraySize <= *stackSize)
    {
        // Get the new array size by multiplying the arraySize by 2.
        newArraySize = new int(*arraySize * 2);

        // Delete the memory of the array size and set to nullptr.
        delete arraySize;
        arraySize = nullptr;

        // Set the array size to the new array size.
        arraySize = new int(*newArraySize);

        // Create a new item array with the new array size.
        T* newItemArray = new T[*arraySize];

        // Copy the item array contents into the new item array.
        for (int loop = 0; loop < *stackSize; ++loop)
        {
            newItemArray[loop] = itemArray[loop];
        }

        // Delete the old item array memory.
        delete[] itemArray;
        itemArray = newItemArray;

        // Delete the new array size.
        delete newArraySize;
    }

    // Push the new item data to the item array using stack size.
    itemArray[*stackSize] = data;

    // Increase the stack count by 1.
    *stackSize += 1;
}

/// <summary>
/// This function returns the last added data in the item array.
/// </summary>
/// <typeparam name="T">The generic data type.</typeparam>
template<class T>
inline T& Stack<T>::Top()
{
    // If stack size is 0.
    if (*stackSize == 0)
    {
        // Throw an exception error.
        throw out_of_range("Stack is empty!");
    }

    // Return the last data in the item array.
    return itemArray[*stackSize - 1];
}

/// <summary>
/// This function removes the last added data in the item array.
/// </summary>
/// <typeparam name="T">The generic data type.</typeparam>
template<class T>
inline void Stack<T>::Pop()
{
    // Throw an exception if the stack size is 0.
    if (*stackSize == 0)
    {
        throw out_of_range("Stack is empty!");
    }

    // Set the last item on the stack.
    // delete itemArray[*stackSize - 1];
    // itemArray[*stackSize - 1] = nullptr;

    // Reduce the stack size by 1.
    *stackSize -= 1;
}

/// <summary>
/// This function print all the generic elements in the item array.
/// </summary>
/// <typeparam name="T">The generic data type.</typeparam>
template<class T>
inline void Stack<T>::Print()
{
    // If the stack size is 0, throw exception.
    if (*stackSize == 0)
    {
        throw out_of_range("Stack is empty!");
    }

    // Else print the items.
    for (int loop = 0; loop < *stackSize; ++loop)
    {
        if (loop != *stackSize - 1)
        {
            // Print.
            cout << itemArray[loop] << ", ";
        }
        else
        {
            // Print.
            cout << itemArray[loop] << ".";
        }
    }

    // End the line.
    cout << endl;
}

/// <summary>
/// This function returns the number of generic elements in the item
/// array.
/// </summary>
/// <typeparam name="T">The generic data type.</typeparam>
/// <returns>An int.</returns>
template<class T>
inline int Stack<T>::Getsize()
{
    // TODO: insert return statement here
    // If the stack size is 0, throw exception.
    if (*stackSize == 0)
    {
        throw out_of_range("Stack is empty!");
        return 0;
    }

    // Else return stack size.
    return *stackSize;
}

/// <summary>
/// This function returns true if there is an element in the item
/// array.
/// </summary>
/// <typeparam name="T">The generic data type.</typeparam>
/// <returns>A bool.</returns>
template<class T>
inline bool Stack<T>::IsEmpty()
{
    // If the stack size is not 0, return true.
    if (*stackSize != 0)
    {
        return true;
    }

    // Else return false.
    return false;
}
