#include <iostream>
using namespace std;

/// <summary>
/// Calculates average score based on entries.
/// </summary>
/// <param name="scoresRead">A float score</param>
/// <param name="numberOfEntries">A int for number of entries</param>
void AverageScore(float* scoresRead, int numberOfEntries)
{
	float number = 0;

	// Use pointer and dereference values.
	for (int loop = 0; loop < numberOfEntries; ++loop)
	{
		// Check  loop is not the last loop
		if (loop != numberOfEntries)
		{
			// Add all number.
			number += scoresRead[loop];
		}
	}
	// Calculate average score.
	number = number / numberOfEntries;

	// Print out values.
	cout << "Average Score is < " << number << " >" << endl;
}

/// <summary>
/// Calculate high score based on entries.
/// </summary>
/// <param name="scoresReadPointer">A float pointer for scores</param>
/// <param name="numbersOfEntries">A int for number of entries</param>
void HighScore(float* scoresReadPointer, int numberOfEntries)
{
	float number = -999999999;

	// Use pointer and dereference values.
	for (int loop = 0; loop < numberOfEntries; ++loop)
	{
		// Check  loop is not the last loop
		if (loop != numberOfEntries)
		{
			// Check if number of score larger.
			if (scoresReadPointer[loop] > number)
			{
				number = scoresReadPointer[loop];
			}
		}
	}

	// Print out values.
	cout << "High Score is < " << number << " >" << endl;
}