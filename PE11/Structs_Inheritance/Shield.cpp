#include "Shield.h"

Shield::Shield() : Item()
{
}

Shield::Shield(std::string _name, int _damage, int _weight) :
	Item(_name, _damage, _weight)
{
}

Shield::~Shield()
{
}

void Shield::print()
{
	Item::print();
}
