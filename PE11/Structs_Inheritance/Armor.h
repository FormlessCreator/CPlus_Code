#pragma once
#include "Item.h"
class Armor : public Item
{
public:
	Armor();
	Armor(std::string _name, int _damage, int weight);
	~Armor();
	void print() override;
};

