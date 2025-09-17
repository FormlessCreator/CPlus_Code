#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <GravitySnake.h>
#include <iomanip>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include <memory>
using namespace std;
using namespace sf;

/* GravitySnake.h is the header file for a dynamically linked library (dll) called
* GravitySnake.dll. The GravitySnake library is a set of functions that satisfy the
* requirements of HW2 - Gravity Snake. In order to allow you to complete HW3 without
* the need for a done version of HW2, this DLL has been created. Using it's functions,
* you can implement HW3 without the HW2 code. A full breakdown of it's functions
* can be found in the homework document.
*/

/*
 * Snake Game - Original Version by [Austin Willoughby]
 *            - Custom Version by [Mayowa Famade]
 *
 * Features added:
 * - Custom graphical interface with snake body represented as a green snake head.
 * - Custom graphical interface for wall boundary and target.
 * - Custom graphical interface for points gained by player during gameplay.
 * - Added a main menu with options on how start the game, move the snake, and win the game.
 * - Point mechanic: Point increases by 10 points if the an even target is collected within 3 seconds.
 *
 * File: main.cpp
 * Date: [11/14/2024]
 *
 * Description:
 * This file contains the main game loop and logic for the custom Snake game.
 * The game starts with a menu, and the user can play the game, where they control the snake
 * The goal is to collect a 100 points.
 */

int main()
{
	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	//Sets the possible bounds of where the target can spawn (-3, -3) to (3, 3) here.
	//This function is from the DLL.
	// Changed the DLL function from 4 to 3 to fit drawn shape.
	setTargetBounds(-3.0f, 3.0f, -3.0f, 3.0f);

	//Create the physics world, and all the objects. Return a pointer to the snake body.
	//These functions are from the DLL.
	// Store the created objects in a smart pointer.
	// Changed values of 6.f to 5.2f.
	initVariables(b2Vec2(0.0f, -9.8f));
	createFloor(b2Vec2(0.0f, -5.2f), 10.0f, 1.0f);
	createCeiling(b2Vec2(0.0f, 5.2f), 10.0f, 1.0f);
	createLeftWall(b2Vec2(-5.2f, 0.0f), 1.0f, 10.0f);
	createRightWall(b2Vec2(5.2f, 0.0f), 1.0f, 10.0f);
	b2Body* snake = createSnake(b2Vec2(0.0f, 5.0f), 0.5f, 0.5f);

	// 1 Box2D meter = 50.0f SFML pixel.
	// Create a snake rectangular body.
	float snakeSize = 50.0f;
	RectangleShape snakeShape(Vector2f(snakeSize, snakeSize));

	// Create a target circle body.
	CircleShape targetShape(20.0f);

	// Create rectangle shape body for the box wall boundaries all in a unique pointer.
	unique_ptr<RectangleShape> floor = ConvertBoxToShape(b2Vec2(-5.0f, -13.0f), 10.0f, 1.0f);
	unique_ptr<RectangleShape> ceiling = ConvertBoxToShape(b2Vec2(-5.0f, 5.0f), 10.0f, 1.0f);
	unique_ptr<RectangleShape> leftWall = ConvertBoxToShape(b2Vec2(-5.0f, 5.0f), 1.0f, 10.0f);
	unique_ptr<RectangleShape> rightWall = ConvertBoxToShape(b2Vec2(13.0f, 5.0f), 1.0f, 10.0f);

	// Debug.
	/*floor->setFillColor(Color::Yellow);
	ceiling->setFillColor(Color::Green);
	leftWall->setFillColor(Color::Red);
	rightWall->setFillColor(Color::Blue);*/
	
	// The initial number of target collected.
	int targetsCollected = 0;
	int points = 0;

	// Use a created window for display.
	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Snake");

#pragma region Import and Set Textures:
	// Add a texture to the wall.
	Texture wallTexture;

	// Load image and check to see if image is successfully loaded.
	if (!wallTexture.loadFromFile("Assets/wall.png"))
	{
		// Print error.
		cout << "Error: The wall Texture is not found." << endl;
	}

	// Add the texture to a the wall borders.
	floor->setTexture(&wallTexture);
	ceiling->setTexture(&wallTexture);
	leftWall->setTexture(&wallTexture);
	rightWall->setTexture(&wallTexture);

	// Create a texture for the snake.
	Texture snakeTexture;

	// Load image and check to see if image is successfully loaded.
	if (!snakeTexture.loadFromFile("Assets/Snake.png"))
	{
		// Print error.
		cout << "Error: The Snake Texture is not found." << endl;
	}

	// Set the snake shape texture to the snake shape.
	snakeShape.setTexture(&snakeTexture);

	// Create an ash border around target.
	targetShape.setOutlineThickness(5.0f);
	targetShape.setOutlineColor(sf::Color(128, 128, 128));
#pragma endregion

#pragma region Import and Set Fonts:
	// Create a font and load the font file.
	Font introAndGameOverFont;
	Font scoreDisplay;
	Font newDisplay;

	// Import fonts and check if the fonts are successfully imported.
	if (!introAndGameOverFont.loadFromFile("Debug/Fonts/Jacquard_12/Jacquard12-Regular.ttf"))
	{
		// Print error.
		cout << "The Intro and Game Over font is not imported." << endl;
	}

	if (!scoreDisplay.loadFromFile("Debug/Fonts/Micro_5/Micro5-Regular.ttf"))
	{
		// Print error.
		cout << "The Score Display font is not imported." << endl;
	}

	if (!newDisplay.loadFromFile("Debug/Fonts/Babas_Neue/BebasNeue-Regular.ttf"))
	{
		// Print error.
		cout << "The New Display font is not imported." << endl;
	}

	// Create a Text for title, instruction and game over state.
	// Use the font with text to set font size, color and position.
	Text title("Welcome to Gravity Snake", introAndGameOverFont, 75);
	title.setFillColor(Color::White);
	title.setPosition(200, 100);

	Text instructions("Press \"Enter\" to Start", scoreDisplay, 40);
	instructions.setFillColor(Color::Black);

	Text controls("Use \"A (left), W (up), D (Right)\" to move the snake", newDisplay, 35);
	controls.setFillColor(Color::White);

	Text goal("Collect 100 points to win the game!", scoreDisplay, 45);
	goal.setFillColor(Color(255, 215, 0));

	Text score("Points: " + to_string(points), scoreDisplay, 45);
	score.setFillColor(Color::Black);

	Text gameOver("\t\t[ Game Over ]\nYou have won the Game!", introAndGameOverFont, 60);
	title.setFillColor(Color::White);

	// Get the window width.
	float windowWidth = window.getSize().x;

	// Center the text for introduction screen.
	centerText(title, windowWidth, 150, true, Color::Black, 1.5f);
	centerText(instructions, windowWidth, 300, true, Color::White, 1.0f);
	centerText(controls, windowWidth, 400, false, Color::Black, 1.0f);   
	centerText(goal, windowWidth, 500, true, Color::Black, 1.0f);

	// Center text for Game Over!
	centerText(gameOver, windowWidth, 250, true, Color::Black, 1.5f);

	// Center the text to keep track of score.
	// Place the point to the top middle section of the game window.
	centerText(score, windowWidth, 80, true, Color::White, 1.0f);
#pragma endregion

	// Create a bool input for state change display.
	bool gameStarted = false;

	// Use clock for scoring!
	Clock clock;

	// Time to store interval between hitting target.
	Time timer;

	// Display the welcome screen before the game starts.
	// Using a new window.
	while (window.isOpen() && !gameStarted)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			// Check for the Enter key to start the game
			// Else this window keeps running.
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				gameStarted = true;
			}
		}

		// Clear the window with a mild pink background
		window.clear(Color(240, 128, 128));

		// Draw title and instructions
		window.draw(title);
		window.draw(instructions);
		window.draw(controls);
		window.draw(goal);

		// Display everything we have drawn so far
		window.display();
	}

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		// clear the window with black color
		window.clear(sf::Color(255, 182, 193));

#pragma region Get SFML Position to Draw Shapes:
		/* Get the position of the snake Box 2d and
		 * convert to SFML. */
		 // 1 Box2D meter = 50.0f SFML pixel.
		b2Vec2 snakeBoxPosition = snake->GetPosition();
		Vector2f snakeSfmlPosition = ConvertToSFML(snakeBoxPosition);

		// Set the snake shape position to the new SFML position.
		snakeShape.setPosition(snakeSfmlPosition);

		// Set the origin using the radius of the shape.
		snakeShape.setOrigin(25.0f, 25.0f);

		// Set the snake shape colour to white.
		snakeShape.setFillColor(Color::White);

		// Convert the target's position to SFML.
		Vector2f targetPosition = ConvertToSFML(getTargetPosition());

		// Set the origin and position of the target to the target shape.
		targetShape.setPosition(targetPosition.x, targetPosition.y);
		targetShape.setOrigin(targetShape.getRadius(), targetShape.getRadius());
#pragma endregion
		
		if (points < 100)
		{
			//This function advances the physics world by deltaTime, and returns the deltaTime in seconds.
			//This function is from the DLL.
			float deltaTime = updateWorldAndReturnDeltaTime();

			//Process input and apply forces to the snake.
			//This function is in Functions.h.
			handleInput();

			//Display the current target and snake positions.
			//This function is in Functions.h, and won't be used in the final HW3.
			display(snake);

			//This function checks if the snake is close to the target. It takes in a maximum collision distance.
			//This function is from the DLL.
			if (checkCollisionAndMoveTarget(0.5f))
			{
				targetsCollected++;

				// Increase score by 5 if 2 targets are collected within 2 seconds:
				// Start the timer if the target collected is 1.
				if (targetsCollected == 1)
				{
					// Get the time.
					timer = clock.getElapsedTime();

					// Set score point to 5.
					points += 5;
				}

				// Target collected is 2.
				if (targetsCollected == 2)
				{
					// Get the current time that have passed since clock has started.
					Time currentTime = clock.getElapsedTime() - timer;

					// Convert the current time to seconds and check if it is less than 3 seconds.
					if (currentTime.asSeconds() < 3.0f)
					{
						// If it is increase score by 10.
						points += 10;

						// Restart the clock
						clock.restart();

						// Reset the target collected to 0.
						targetsCollected = 0;
					}
					else
					{
						// Increase point normally by 5.
						points += 5;

						// Reset the target collected to 0.
						targetsCollected = 0;
					}
				}

				// Set the new point.
				score.setString("Score: " + to_string(points));
			}
		}
		else
		{
			// If point is greater or equal to 100.
			// Change the color and text of game over.
			gameOver.setCharacterSize(70);
			gameOver.setFillColor(Color(255, 215, 0));
		}

		// draw everything here...
		// window.draw(...);
		// If the points is less than 100.
		// Draw the normal game window.
		if (points < 100)
		{
			window.draw(snakeShape);
			window.draw(targetShape);
			window.draw(*floor);
			window.draw(*ceiling);
			window.draw(*leftWall);
			window.draw(*rightWall);
			window.draw(score);
		}
		else
		{
			// Draw the game over screen!
			window.draw(gameOver);
		}

		// end the current frame
		window.display();
	}

	// Delete the snake body and set it to null.
	releaseVariables();

	// Clear memory leaks.
	_CrtDumpMemoryLeaks();


	/* The following block of code is from the SFML drawing tutorial. To accomplish
	* the requirements of HW3, you will need to take the code above and modify it
	* to work within the code provided below. Rather than using the display() method
	* like above, you will need to render shapes to represent the walls, snake, and
	* target.
	* 
	* Note, you should be creating your SFML shapes BEFORE the while (window.isOpen())
	* loop, then render them WITHIN the loop. Additionally, the while(targetsCollected < 2)
	* loop from up above will need to be turned into an if statement so that it doesn't
	* block SFML from rendering new frames to the window.
	*/
}