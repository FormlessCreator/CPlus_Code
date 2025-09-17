#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void display(b2Body* snake);
void handleInput();
sf::Vector2f ConvertToSFML(b2Vec2 objectPosition);
std::unique_ptr<sf::RectangleShape> ConvertBoxToShape(b2Vec2 objectPosition, float width, float height);
void centerText(sf::Text& text, float windowWidth, float yPosition, bool setOutline, sf::Color outlineColor, float outlineThickness);