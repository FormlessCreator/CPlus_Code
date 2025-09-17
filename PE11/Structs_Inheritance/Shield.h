#pragma once
#include "Item.h"
class Shield : public Item
{
public:
	Shield();
	Shield(std::string _name, int _damage, int _weight);
	~Shield();
	void print() override;
};

