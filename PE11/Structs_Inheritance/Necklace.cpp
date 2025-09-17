#include "Necklace.h"

Necklace::Necklace() : Item()
{
}

Necklace::Necklace(std::string _name, int _Damage, int _weight) :
	Item(_name, _Damage, _weight)
{
}

Necklace::~Necklace()
{
}

void Necklace::print()
{
	Item::print();
}
