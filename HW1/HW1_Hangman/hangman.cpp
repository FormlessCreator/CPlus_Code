// ASCII Art by ChrisHorton.
// Link: https://gist.github.com/chrishorton/8510732aa9a80a03c829b09f12e20d9c

#include <iostream>
#include <cstring>
#include "hangman.h"
using namespace std;

// Use this after an input for a single character
// is entered as if multiple characters are entered
// the loop will run for each character in the input.
// cin.ignore(numeric_limits<streamsize>::max(), '\n');

/// <summary>
/// This method draws the hangman ASCII art based on 
/// number of incorrect guesses given.
/// </summary>
/// <param name="wrongGuessesRemaining">
/// The number of times a guess is wrong.</param>
void showGallows(int wrongGuessesRemaining)
{
	// Create ASCII art with differnt characters.
	// Store characters in array.
	char input[100] =
		"  +---+\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input1[100] =
		"  +---+\n"
		"  |   |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input2[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input3[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		"  |   |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input4[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		" /|   |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input5[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		" /|+  |\n"
		"      |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input6[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		" /|+  |\n"
		"  |   |\n"
		"      |\n"
		"      |\n"
		"=========";

	char input7[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		" /|+  |\n"
		"  |   |\n"
		" /    |\n"
		"      |\n"
		"=========";

	char input8[100] =
		"  +---+\n"
		"  |   |\n"
		"  O   |\n"
		" /|+  |\n"
		"  |   |\n"
		" / >  |\n"
		"      |\n"
		"=========";

	// Use the switch statement to draw gallows:
	// Based on the number of wrong guesses.
	switch (wrongGuessesRemaining)
	{
	case 0:
		cout << input << endl;
		break;

	case 1:
		cout << input1 << endl;
		break;

	case 2:
		cout << input2 << endl;
		break;

	case 3:
		cout << input3 << endl;
		break;

	case 4:
		cout << input4 << endl;
		break;

	case 5:
		cout << input5 << endl;
		break;

	case 6:
		cout << input6 << endl;
		break;

	case 7:
		cout << input7 << endl;
		break;

	case 8:
		cout << input8 << endl;
		break;
	}
}

/// <summary>
/// This methods properly displays the incorrect
/// and correct guesses the player made.
/// </summary>
/// <param name="word">The word to be guessed</param>
/// <param name="correctGuesses">The correct guess</param>
/// <param name="incorrectGuesses">The incorect guess</param>
void showSolveDisplay(
	char word[],
	char correctGuesses[], 
	char incorrectGuesses[])
{
	// Create a character [] that keeps tracks of
	// correct word.
	char BlankCharArray[15] = "";

	// Get the lenght of word character array.
	int wordLenght = strlen(word);
	int loop = 0;

	// Fill the BlankCharArray with stars.
	// Using word lenght.
	for (int loop = 0; loop < wordLenght; ++loop)
	{
		BlankCharArray[loop] = '*';
	}

	// Display the incorrect guesses.
	// If the incorrect guess first character is empty:
	// Print a blank word.
	if (incorrectGuesses[0] == '\0')
	{
		// Print and empty space.
		cout << "\nIncorrect guesses: " << endl;
	}
	else
	{
		// Print out the incorrect guesses.
		cout << "\nIncorrect guesses: " << incorrectGuesses << endl;
	}

	// Create a number to keep track of character without star.
	// It resets to 0 each funtion call.
	int charTracker = 0;

	// Using a for loop.
	for (loop = 0; loop < wordLenght; ++loop)
	{
		// If the loop is a star character.
		if (BlankCharArray[loop] == '*')
		{
			// Checks character of the word array
			// Against all the correct guesses.
			for (int loop2 = 0; loop2 < wordLenght; ++loop2)
			{
				// Compare guess char to all word char.
				if (correctGuesses[loop] == word[loop2])
				{
					// Fill the blankChar[] with word char.
					BlankCharArray[loop2] = correctGuesses[loop];
				}
			}
		}
	}

	// Use for loop to figure out letters left to guess.
	for (loop = 0; loop < wordLenght; ++loop)
	{
		// If word is star increase char tracker by 1.
		if (BlankCharArray[loop] == '*')
		{
			// Add one to tracker.
			charTracker += 1;
		}
	}
	// Print out the blank character array.
	cout << "Word to solve: " << BlankCharArray << endl;

	// Tell the user how many word is left to guess!
	cout << "\n" << charTracker << " letters left to guess!"
		<< endl;

}