#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#endif // !SNAKE_H

#include <ctime>
#include <Box2D/Box2D.h>

void update(b2World* world, float deltaTime);
void display(b2Vec2* target, b2Vec2 playerPosition, bool targetIsHit);
void applyForces(char input, b2Body* snakeBody);
void moveTarget(b2Vec2* target);
b2Body* createWalls(b2World* world,float xPosition, float yPosition, float width, float height);
float CalcualteDistance(b2Vec2 playerPosition, b2Vec2* target);