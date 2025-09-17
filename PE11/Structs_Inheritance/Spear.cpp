#include "Spear.h"
#include "Item.h"
Spear::Spear() : Item()
{
}

Spear::Spear(std::string _name, int _damage, int _weight) :
	Item(_name, _damage, _weight)
{
}

Spear::~Spear()
{
}

void Spear::print()
{
	Item::print();
}
