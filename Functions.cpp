#include "Functions.h"
#include <iostream>
#include <GravitySnake.h>
#include <conio.h>
#include <memory>
using namespace std;

void display(b2Body* snake)
{
	cout << "Target: (" << getTargetPosition().x << ", " << getTargetPosition().y << ")  ";
	cout << "Snake: (" << snake->GetPosition().x << ", " << snake->GetPosition().y << ")  " << endl;
}

void handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		applyForceToSnake(b2Vec2(0.0f, 100000.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyForceToSnake(b2Vec2(-10000.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyForceToSnake(b2Vec2(10000.0f, 0.0f));
	}
}

/// <summary>
/// This converts an object Box2d position to its
/// respective sfml coordinate.
/// </summary>
/// <param name="objectPosition">The object b2Vec2</param>
/// <returns>A Vector2f.</returns>
sf::Vector2f ConvertToSFML(b2Vec2 objectPosition)
{
	// Field:
	// Create a new x and y coordinate.
	// Using the current x and y position of the object's position.
	float sfmlXCoordinate = (objectPosition.x + 5) * 80;
	float sfmlYCoordinate = 800 - (objectPosition.y + 5) * 80;

	// Using the x and y coordinate:
	// Create a new SFML coordinate for object. 
	sf::Vector2f newSfmlCoordinate(sfmlXCoordinate, sfmlYCoordinate);

	// Return the new vector2f SFML position.
	return newSfmlCoordinate;
}

/// <summary>
/// Create a SFML box held in a smart pointer using the object's
/// Box2d position, height and width.
/// </summary>
/// <param name="objectPosition">The object's box position.</param>
/// <param name="width">The object's width.</param>
/// <param name="height">The object's height.</param>
/// <returns>A unique pointer to the created sfml Rectangular Shaped box.</returns>
std::unique_ptr<sf::RectangleShape> ConvertBoxToShape(b2Vec2 objectPosition, float width, float height)
{
	// SFML pixel scale:
	float scale = 80.0f;

	// Get the sfml position of the object using the Convert to SFML.
	sf::Vector2f newPosition = ConvertToSFML(objectPosition);

	// Create a new SFML size for the width and height.
	// Using the scale.
	float sfmlWidth = (width) * scale;
	float sfmlHeight = (height) * scale;
	float scaleBoxX = objectPosition.x * scale;

	// Create a new Rectangle shape smart pointer.
	unique_ptr<sf::RectangleShape> box = 
		make_unique<sf::RectangleShape>(sf::Vector2f(sfmlWidth, sfmlHeight));

	// Set the position and origin of the box.
	box->setPosition(newPosition);
	box->setOrigin(newPosition.x / 2, newPosition.y / 2);

	// Return the unique pointer to the sfml box.
	return box;
}

/// <summary>
/// This centers a text in the middle of the window.
/// </summary>
/// <param name="text">The text.</param>
/// <param name="windowWidth">The window width.</param>
/// <param name="yPosition">The y position.</param>
/// <param name="setOutline">Set an outline if true.</param>
/// <param name="outlineColor">Set an outline color.</param>
/// <param name="outlineThickness">Set an outline thickness.</param>
void centerText(sf::Text& text, float windowWidth, float yPosition,
	bool setOutline, sf::Color outlineColor, float outlineThickness)
{
	// Get the text width using the get local bounds.
	float textWidth = text.getLocalBounds().width;

	// Get the center X position for the text in the window.
	float centerXPosition = (windowWidth - textWidth) / 2;

	// Set an outline if true.
	if (setOutline)
	{
		// Create a color and thickness for text outline.
		text.setOutlineColor(outlineColor);
		text.setOutlineThickness(outlineThickness);
	}

	// Set the text X position at the new center.
	// Also use the Y position.
	text.setPosition(centerXPosition, yPosition);
}

