#pragma once
#include "Player.h"
class Fighter : public Player
{
private:
	char* weaponSkill;

public:
	Fighter();
	Fighter(const char* _name, const char* _weaponSkill, int _strength, int _endurance, int _intelligence, int _luck);
	~Fighter();
	void printFighter();
};

