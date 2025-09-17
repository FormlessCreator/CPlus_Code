#include "Armor.h"

Armor::Armor(): Item()
{
}

Armor::Armor(std::string _name, int _damage, int _weight) :
	Item(_name, _damage, _weight)
{
}

Armor::~Armor()
{
}

void Armor::print()
{
	Item::print();
}
