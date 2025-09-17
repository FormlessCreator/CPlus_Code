// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hangman.h"
using namespace std;

int main()
{
    // Create a 3 character array with and empty character;
    char word[9] = "absolute";
    char correctLetters[100] = "";
    char wrongLetters[100] = "";
    char input;
    int wrongGuess = 0;
    int correctGuess = 0;

    // Create a loop tracker.
    // Create a times loop run using word
    int loop = 0;
    int wordLenght = strlen(word);

    // Introduce the player to the game.
    cout << "\t - - - - + [ WELCOME TO HANGMAN ] + - - - - \n" << endl;
    cout <<
        "Hangman is a word guessing game.\n"
        "A word is given and you have " << wordLenght <<
        " chances to guess the word letters. \n"
        "If you guess the wrong letter " << wordLenght <<
        " times you lose the game!\n"
        "If you fail to guess the letters each time, your stick man will hang!\n" 
        "If a correct letter is given, a hint of the hidden word is shown.\n"<< endl;

    // Create a for loop that loop based on the lenght of given word.
    while (wrongGuess != 8)
    {
        // Get the number of guesses.
        int guessesLeft = wordLenght - wrongGuess;

        // Tell user letters remaing to guess.
        cout << "You have " << guessesLeft << " guesses left!" << endl;

        // Prompt the player for input and get input.
        cout << "Please, guess a letter: ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Check to see if the letter is part of the word.
        // And the word is not part of correct letter.
        // Use using strchr.
        if(strchr(word, input))
        {
            // Print the guess is correct!
            cout << "The word contains the letter '" << input 
                << "'!\n" << endl;

            // Add the input in the correct word array.
            // Using correctGuess.
            correctLetters[correctGuess] = input;

            // Increase correct guess number.
            correctGuess += 1;
        }
        else
        {
            // Print the guess is incorrect.
            cout << "The word does not contains the letter '" 
                << input << "'!\n" << endl;

            // Add the input in the wrong word array.
            // Using wrongGuess.
            wrongLetters[wrongGuess] = input;

            // Increase wrong guess number.
            wrongGuess += 1;
        }

        // Use the show gallows.
        showGallows(wrongGuess);

        // Use the ShowSolveDisplays();
        showSolveDisplay(word, correctLetters, wrongLetters);

        // If the hangman is on the last try, tell
        // the player they have lost!
        // If wrongGuess.
        if (wrongGuess == wordLenght)
        {
            // Tell player 0 guesses are left!
            // You lose!
            cout << "\nYou lose!!!" << endl;
        }

        // If the correct guess is given 8 times
        // the user wins!
        if (correctGuess == wordLenght)
        {
            // Tell player they win!
            cout << "\nYou Win!!!" << endl;

            // Break the code to end loop.
            break;
        }
   }

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
