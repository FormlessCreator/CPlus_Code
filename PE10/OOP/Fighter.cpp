#include "Fighter.h"
#include <iostream>
using namespace std;

/// <summary>
/// A defualt fighter constructor.
/// </summary>
Fighter::Fighter() :
	Player()
{
	weaponSkill = new char[10] {"Revibrate"};
}

/// <summary>
/// A parameterized fighter constructor using
/// its parent param.
/// </summary>
/// <param name="_name"></param>
/// <param name="_weaponSkill"></param>
/// <param name="_strength"></param>
/// <param name="_endurance"></param>
/// <param name="_intelligence"></param>
/// <param name="_luck"></param>
Fighter::Fighter(const char* _name, const char* _weaponSkill, int _strength, int _endurance, int _intelligence, int _luck) :
	Player(_name, _strength, _endurance, _intelligence, _luck)
{
	// if the pointer for weapon skill is not empty.
	if (weaponSkill != nullptr)
	{
		// Delete the memory allocation of weapon skill.
		delete[] weaponSkill;
	}

	// Get the length of _weapon skill with the null terminator.
	int length = strlen(_weaponSkill) + 1;

	// Create a new memory with new length for weapon skill.
	weaponSkill = new char[length];

	// Copy _weaponSkill to weapon skill.
	strcpy_s(weaponSkill, length, _weaponSkill);
}

/// <summary>
/// The fighter class deconstructor.
/// </summary>
Fighter::~Fighter()
{
	// Delete weapon skill;
	delete[] weaponSkill;
}

/// <summary>
/// This prints out figher infomation with the parent
/// class print information.
/// </summary>
void Fighter::printFighter()
{
	// Call the base class print method.
	PrintPlayer();

	// Print the player fighter's skill.
	cout << "Fighter's weapon skill: [" << weaponSkill << "]\n" << endl;
}
