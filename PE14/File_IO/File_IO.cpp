// File_IO.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Create an ofstream object.
    ofstream ofOutFileObject = ofstream("newtextfile.txt");

    // Check if the file is open.
    if (ofOutFileObject.is_open())
    {
        // Write into the file.
        ofOutFileObject << "This is my first C++ ofstream object" << endl; 
        ofOutFileObject << "This is fun!" << endl;
        ofOutFileObject << "Thank you!" << endl;

        // Close after placing text in the file.
        ofOutFileObject.close();
    }

    // Read in the created file by using an ifstream object.
    ifstream readInFileObject;

    // Using the ios::binary open the read in file.
    readInFileObject.open("newtextfile.txt", ios::binary);

    // Create a string to store characters line.
    string binaryLines;

    // Use a while loop to get each lines in file while the file is good
    // and not at the end.
    while (readInFileObject.good())
    {
        // Create a new string.
        string line;

        // Get the current line and store in string.
        getline(readInFileObject, line);

        // Add the line with a \n for new line.
        binaryLines += line + "\n";
    }

    // Close the stream.
    readInFileObject.close();

    // Open file again.
    readInFileObject.open("newtextfile.txt");

    // Create a string to directly read the entire text characters of file to one string.
    // In one line;
    string directFileRead = 
        string(istreambuf_iterator<char>(readInFileObject), istreambuf_iterator<char>());

    // Close the stream.
    readInFileObject.close();

    // Print out both of the strings
    cout << "This is the string value read in iostream mode: \n" << binaryLines << endl;

    cout << "\nThis is the string value of file read in its entirety at once: \n" << directFileRead << endl;

    // -- Other way by using character array. --
    // Create a 200 character array to store the characters in the text file.
    // With a null terminator.
    // char textCharacter[200] = "";

    // Read in the text file character in the character array.
    // With the amount of character to read using ifstream object and read method.
    // readInFileObject.read(textCharacter, 200);

    // Clear the read cursor.
    // readInFileObject.clear();

    // Reset the cursor reader to the first character in file.
    // readInFileObject.seekg(0);
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
