#pragma once
#include <mutex>
class GamePlay
{
public:
	std::string name;
	GamePlay(std::string _name);
	~GamePlay();
	void Update(std::mutex* mutexPointer);
};

