#pragma once
#include "Item.h"
#include <string>

class Spear : public Item
{
public:
	Spear();
	Spear(std::string _name, int _damage, int _weight);
	~Spear();
	void print() override;
};

