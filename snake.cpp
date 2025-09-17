#include <iostream>
#include <conio.h>
#include <iomanip>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <cstdlib> // For rand()
#include <ctime>
#include <cmath>
#include "snake.h"
using namespace sf;
using namespace std;

/// <summary>
/// This function updates the physics world using delta time
/// and the world body pointer.
/// </summary>
/// <param name="world">The world body pointer.</param>
/// <param name="deltaTime">The delta time seconds.</param>
void update(b2World* world, float deltaTime)
{
    // Get deltaTime as seconds.
	// World step using the seconds that have passed.
	world->Step(deltaTime, 6, 2);
}

/// <summary>
/// This function print out the snake and targets position.
/// </summary>
/// <param name="targetPosition">The targets position.</param>
/// <param name="playerPosiion">The player's position.</param>
void display(b2Vec2* target, b2Vec2 playerPosition, bool targetIsHit)
{
    // Get the x and y of target.
    float targetXPosition = target->x;
    float targetYPosition = target->y;

    if (targetIsHit)
    {
        // Print the player position and target position.
        cout << "\nTarget: " << targetXPosition << " , " << targetYPosition <<
            "- - > Snake: " << playerPosition.x << " , " << playerPosition.y <<
            " (Hit target)\n" << endl;
    }
    else
    {
        // Print the player position and target position.
        cout << "Target: " << targetXPosition << " , " << targetYPosition <<
            "- - > Snake: " << playerPosition.x << " , " << playerPosition.y <<
            endl;
    }
}


/// <summary>
/// This function creates a wall body in the world and returns
/// a wall body pointer.
/// </summary>
/// <param name="world">The world pointer</param>
/// <param name="xPosition">The x position of the wall.</param>
/// <param name="yPosition">The y position of the wall.</param>
/// <param name="width">The width of the wall.</param>
/// <param name="height">The height of the world.</param>
/// <returns>Returns a wall body.</returns>
b2Body* createWalls(b2World* world,float xPosition, float yPosition, float width, float height)
{
    // Create a wall body defination.
    b2BodyDef wallBodyDef;

    // Set the position of the ground body in the world.
    wallBodyDef.position.Set(xPosition, yPosition);

    // Create a static body position for wall.
    wallBodyDef.type = b2_staticBody;

    // Create a ground plaform within the ground body.
    // Use a pointer to get the memory address of the body def.
    b2Body* wallBody = world->CreateBody(&wallBodyDef);

    // Create a polygon shaped body for wall.
    b2PolygonShape wallBox;

    // Create a wall shape using half-height.
    // Remeber to divide by 2 for actual representation.
    wallBox.SetAsBox(width / 2, height / 2);

    // Create fixture for the wall box.
    b2FixtureDef wallFixture;

    // Set the fixture shape to wall box.
    wallFixture.shape = &wallBox;
    wallFixture.density = 0.0f;

    // Create fixture that places the box shape in the world.
    // The density of 0.0f means forces won't act on the box.
    wallBody->CreateFixture(&wallFixture);

    // Return the wall body pointer.
    return wallBody;
}

/// <summary>
/// This function applies forces based on key presses using
/// continious input.
/// </summary>
/// <param name="input">The key input pressed.</param>
void applyForces(char input, b2Body* snakeBody) 
{
    // Fields:
    bool jump = false;
    float horizontalForce = 625.0f;
    float verticalForce = 1250.0f;
    float jumpForce = 100000.0f;
    

    // Using apply force to center function.
   
    // Check if the space bar is enter.
    // Make it so that player can not jump multiple times.
    if (input == ' ')
    {
        // If the snake has not jump, jump.
        if (!jump)
        {
            // Apply jumpforce.
            snakeBody->ApplyForceToCenter(b2Vec2(0.0f, jumpForce), true);
        }

        // Set jump to true, player has jump in this frame.
        jump = true;
    }

    // If the key is a, move the player left.
    if (input == 'a')
    {
        // Add force to snake body to move left.
        snakeBody->ApplyForceToCenter(b2Vec2(-horizontalForce, 0.0f), true);
    }
    
    // If key is d, move the player right.
    if (input == 'd')
    {
        // Add force to snake body to move right.
        snakeBody->ApplyForceToCenter(b2Vec2(horizontalForce, 0.0f), true);
    }

    // If key is w, move the player up by a small amount.
    if (input == 'w')
    {
        // Add force to snake body to move up.
        snakeBody->ApplyForceToCenter(b2Vec2(0.0f, verticalForce), true);
    }

}

/// <summary>
/// This function moves the target position to a new location.
/// </summary>
/// <param name="target">Target Vector2 position.</param>
void moveTarget(b2Vec2* target)
{
    // Fields:
    float randomYPosition;
    float randomXPosition;
    b2Vec2 targetPosition;

    // Derefrence the target for the x and y position.
    targetPosition = *target;

    // Create a rand seed that is casted to float.
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Get the random x position between -5.0 and 5.0
    randomXPosition = -5.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (10.0f)));

    // Get the random y position between -5.0 and 5.0
    randomYPosition = -5.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (10.0f)));

    // Print the new target distance.
    cout << "\n - - The new target distance is [ X: " << randomXPosition << 
        ", Y: " << randomYPosition << " ] - - \n" << endl;

    // Set the target to the new position
    targetPosition.x = randomXPosition;
    targetPosition.y = randomYPosition;

    // Set target.
    target->Set(targetPosition.x, targetPosition.y);
}

/// <summary>
/// This calculates the distance between the player 
/// position and the snake position.
/// </summary>
/// <param name="playerPosition">The player position.</param>
/// <param name="snakePosition">The snake position.</param>
/// <returns>The distance between the player and target.</returns>
float CalcualteDistance(b2Vec2 playerPosition, b2Vec2* target)
{
    // Get the dereference target position.
    b2Vec2 targetPosition = *target;

    // Find the distanceX between player and snake.
    float distanceX = pow(targetPosition.x - playerPosition.x, 2);

    // Find the distanceY between player and snake.
    float distanceY = pow(targetPosition.y - playerPosition.y, 2);

    // Find the distance.
    float distance = sqrt(distanceX + distanceY);

    // Return the distance.
    return distance;
}