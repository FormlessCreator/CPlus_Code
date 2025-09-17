#include "Player.h"
#include <cstring>
#include <iostream>

/// <summary>
/// Defualt constructor for the Player class.
/// </summary>
Player::Player()
{
	// Create name with reference to heap memory allocation.
	playerName = new char[8] {'U', 'n', 'k', 'n', 'o', 'w', 'n'};

	// Set all other interger stat to 10;
	strength = 10;
	endurance = 10;
	intelligence = 10;
	luck = 10;
}

/// <summary>
/// A parameterized counstructor for the Player class.
/// </summary>
/// <param name="_name">The player's name.</param>
/// <param name="_strenght">The player's strenght.</param>
/// <param name="_endurance">The player's endurance.</param>
/// <param name="_intelligence">The player's intelligence.</param>
/// <param name="_luck">The player's luck.</param>
Player::Player(const char* _name, int _strenght, int _endurance, int _intelligence, int _luck)
{
	// Get the lenght of the new name.
	int lenght = strlen(_name) + 1;

	// Delete the previous memory of playerName.
	delete[] playerName;

	// Create the a new player name pointer with a new lenght.
	playerName = new char[lenght];

	// Copy the _name to the player name.
	strcpy_s(playerName,lenght, _name);

	// Initialize other fields.
	intelligence = _intelligence;
	strength = _strenght;
	endurance = _endurance;
	luck = _luck;
}

/// <summary>
/// This funtion prints out the player's information.
/// </summary>
void Player::PrintPlayer()
{
	// Display player information
	std::cout << "Player name: ";

	// Print out the player's name using for loop;
	for (int loop = 0; loop < strlen(playerName); ++loop)
	{
		std::cout << playerName[loop];
	}
	
	// Endline.
	std::cout << std::endl;

	// Print out stats.
	std::cout << "Strenght: " << strength << std::endl;
	std::cout << "Endurance " << endurance << std::endl;
	std::cout << "Intelligence: " << intelligence << std::endl;
	std::cout << "Luck: " << luck << "\n" << std::endl;
}

/// <summary>
/// This function stands as a deconstructor for the player class.
/// </summary>
Player::~Player()
{
	// Delete the character pointer for player name.
	delete[] playerName;
}
