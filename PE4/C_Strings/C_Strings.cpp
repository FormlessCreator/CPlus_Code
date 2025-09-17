// Name: Mayowa Famade.
// Purpose: PE 4 C strings.
// Date: 9/5/2024.

// Create an include cstring.
// Create an std namespace.
#include <iostream>
#include <cstring>
using namespace std;

/// <summary>
/// This method is the main fuction.
/// </summary>
/// <returns>An integer</returns>
int main()
{
    // Create a 100 and 50 character array.
    // Initialize name characters to variable.
    char firstString[100] = "supercalifragilistic ";
    char secondString[50] = "expialidocious";
    
    // Find the lenght of the string.
    // Use the string lenght function.
    int stringLenght = strlen(firstString);

    // Print the lenght.
    cout << "The lenght of " << firstString
        << " is " << stringLenght << endl;

    // Combine the first and second string
    // Using string concatnate the safe version.
    strcat_s(firstString, secondString);

    // Print out combined result.
    cout << "His name is " << firstString <<
        endl;

    // Find out how many times the character
    // "i" occurs using a while loop.
    char letter = firstString[0];

    // Keep track of the time i occurs.
    int count = 0;
    int loop = 0;

    // While the character is not null terminator.
    while (letter != '\0')
    {
        // If the character is I count is increased.
        if (letter == 'i')
        {
            count++;
        }

        // Increase loop by 1.
        loop++;

        // Change the letter to the next letter.
        letter = firstString[loop];
    }
    
    // Print out count.
    cout << "The number of times is 'i' is in " << 
        firstString << " is " << count << endl;
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
