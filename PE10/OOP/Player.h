#pragma once
class Player
{
public:
	Player();
	~Player();
	Player(const char* _name, int _strenght, int _endurance, int _intelligence, int _luck);
	void PrintPlayer();

private:
	char* playerName;
	int strength;
	int endurance;
	int intelligence;
	int luck;
};
