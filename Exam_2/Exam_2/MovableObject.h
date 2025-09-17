#pragma once
class MovableObject
{
protected:
	int xPosition;
	int yPosition;

public:
	MovableObject(int _xposistion, int _yPosition);
	virtual void Display();
	~MovableObject();
};

