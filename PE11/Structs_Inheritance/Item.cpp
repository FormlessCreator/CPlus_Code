#include "Item.h"
#include <iostream>

/// <summary>
/// This creates a defualt constructor for the
/// item class.
/// </summary>
Item::Item()
{
	name = "Seer's Mark Dagger";
	damage = 27;
	weight = 0.45;
}
/// <summary>
/// This the deconstructor for the item class.
/// </summary>
Item::~Item()
{
	
}

Item::Item(std::string _name, int _damage, int _weight)
{
	// Set parameters values to variables.
	name = _name;
	damage = _damage;
	weight = _weight;
}

/// <summary>
/// This prints outs the items information per
/// line.
/// </summary>
void Item::print()
{
	std::cout << "\nWeapon name: [ " << name << " ]." << std::endl;
	std::cout << "Weapon damage: [ " << damage << " ] hit points." << std::endl;
	std::cout << "Weapon weight: [ " << weight << " ] kg.\n" << std::endl;
}
