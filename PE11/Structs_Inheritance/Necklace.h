#pragma once
#include "Item.h"
#include <string>

class Necklace : public Item
{
public:
	Necklace();
	Necklace(std::string _name, int _Damage, int _weight);
	~Necklace();
	void print() override;
};

