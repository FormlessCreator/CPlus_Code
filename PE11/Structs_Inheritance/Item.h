#pragma once
#include <string>

struct Item
{
protected:
	std::string name;
	float damage;
	float weight;

public:
	Item();
	Item(std::string _name, int _damage, int _weight);
	~Item();
	void virtual print();
}; 

