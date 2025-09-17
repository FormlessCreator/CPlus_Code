#pragma once
#include "MovableObject.h"
class Player :
   virtual protected MovableObject
{
private:
    int size;
    int* inventoryIds;

public:
    Player(int _xPosition, int _yposition);
    void Display() override;
    ~Player();
};

