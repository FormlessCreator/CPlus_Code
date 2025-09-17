#pragma once
#include <string>
#include <vector>

class GameLevel
{
private:
	std::string exitLocation;
	int levelNumber;
	std::vector<std::string> treasures;
	int enemies;

public:
	GameLevel();
	GameLevel(std::string _exitLocation, int _levelNumber, std::vector<std::string> _treasures, int _enemies);
	~GameLevel();
};

