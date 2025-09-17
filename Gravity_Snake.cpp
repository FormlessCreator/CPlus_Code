// Gravity_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Add box 2D.

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <cmath>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "snake.h"

using namespace sf;
using namespace std;

int main()
{
    // Fields:
    char keyInput;
    b2Body* wall1;
    b2Body* wall2;
    b2Body* wall3;
    b2Body* wall4;
    b2Vec2 targetPosition;
    b2Vec2 playerPosition;
    bool targetIsHit;

    // Set all displayed numbers on output to 2 decimal places.
    cout << fixed << setprecision(2);

    // Create gravity simulation using box2d.
    b2Vec2 gravity(0.0f, -9.8f);

    // Define gravity in a world stimulation using box2d.
    // And store on the heap.
    b2World* world = new b2World(gravity);

    // Create a snake body defination that falls dynamically.
    b2BodyDef snakeBodyDef;

    // Give the snake body defination a dynamic body defination.
    snakeBodyDef.type = b2_dynamicBody;

    // Set the position of the snake body def in the world.
    // It should be 4.0 y axis above the ground.
    snakeBodyDef.position.Set(0.0f, 0.0f);

    // Create a snake body pointer that set the snake body
    // defination in the world.
    b2Body* snakeBody = world->CreateBody(&snakeBodyDef);

    // Create a dynamic box polygon shape for the snake.
    // Box height and width = 1.0f(half-height 0.5f).
    b2PolygonShape snakeBox;
    snakeBox.SetAsBox(0.5f, 0.5f);

    // Create fixture that places the box shape in the world.
    // Forces in the world wil act on the box.
    b2FixtureDef snakeFixtureDef;
    snakeFixtureDef.shape = &snakeBox;

    // Change the properties of the snake box.
    snakeFixtureDef.density = 1.0f;
    snakeFixtureDef.friction = 0.3f;

    // Assign fixture to snake body.
    snakeBody->CreateFixture(&snakeFixtureDef);

    // Create an initial target position.
    b2Vec2* target = new b2Vec2(2.0f, 5.0f);

    // Create a message for the player.
    cout << "Welcome to the Gravity Snake Game!" << endl;
    cout << "Your objective is to control the snake and reach the target." << endl;
    cout << "Please > - < Use the following keys to move:" << endl;
    cout << "  - A Key: Move Left" << endl;
    cout << "  - D Key: Move Right" << endl;
    cout << "  - Space Key: Jump" << endl;
    cout << "  - W Key: Move Up (slowly)\n" << endl;
 
    cout << "The target will appear at random positions in the range of (-5.0, 5.0) for both X and Y." << endl;
    cout << "Try to reach the target 3 times. [ Good luck! ]\n" << endl;

    // Wait for user input.
    cout << "Please enter any KEY to continue! " << endl;
    char input = _getch();

    // Create walls with create wall method and store returned
    // wall body pointers.
    wall1 = createWalls(world, 0.0f, 25.0f, 50.0f, 1.0f);    // The top wall.
    wall2 = createWalls(world, 0.0f, -25.0f, 50.0f, 1.0f);   // The bottom wall.
    wall3 = createWalls(world, -25.0f, 0.0f, 1.0f, 50.0f);   // The left wall.
    wall4 = createWalls(world, 25.0f, 0.0f, 1.0f, 50.0f);    // The right wall.

    // Set up the number of target player will need to reach.
    unsigned int targetCounter = 0;

    // Create a boolean variable set to true while the game runs.
    bool running = true;
    bool beforeRunning;

    // Get the seconds that have passed.
    Clock deltaClock;

    // Create a variable to store time that has passed.
    Time deltaTime;

    // Create a distance variable,
    float distance = 0.0f;

    for (int loop = 0; loop < 3; ++loop)
    {

        // If running = false.
        if (running == false)
        {
            // Inform user that a target is hit.
            cout << "\n - > The target is hit! < - \n"
                "[ - Targets hit by you! : " << targetCounter
                << " - ]" << endl;
        }

        // Tell the user the next position of the target.
        moveTarget(target);

        // Set before running and running to true.
        beforeRunning = true;;
        running = true;

        // Wait user input to continue.
        cout << "Please enter 'C' KEY to continue! " << endl;
        input = _getch();

        // The input is not c keep looping.
        while (input != 'c')
        {
            // If input is escape key.
            if (input == 27)
            {
                // Exit game.
                // Inform player that the ESC Key is pressed.
                cout << "\nESC Key was pressed! You have exited the game!"
                    << endl;

                // Return 0 to end the program.
                return 0;
            }
            // Wait user input to continue.
            cout << "Please enter 'C' KEY to continue! " << endl;
            input = _getch();
        }

        // Use a while loop that runs while the game runs.
        // And while the target it is not 3.
        while (running)
        {
            // Create a target is hit boolean.
            targetIsHit = false;

            // Store the time that has passed.
            deltaTime = deltaClock.getElapsedTime();

            // Restart the time to get how much time has passed 
            // since the last frame.
            deltaClock.restart();

            // Call the update method to update the world physics.
            update(world, deltaTime.asSeconds());

            // If the escape key is pressed, running is set to false.
            // Check if a key is pressed.
            if (_kbhit())
            {
                // Get the key input and store it.
                keyInput = _getch();

                // If the key is escape, end the game.
                if (keyInput == 27)
                {
                    // Inform player that the ESC Key is pressed.
                    cout << "\nESC Key was pressed! You have exited the game!"
                        << endl;

                    // Return 0 to end the program.
                    return 0;
                }

                // If key is pressed and it is not the escape key.
                // Call apply forces.
                applyForces(keyInput, snakeBody);

                // Calculate the distance.
                distance = CalcualteDistance(
                    snakeBody->GetPosition(), target);

                // If the target is less than 1.
                if (distance <= 1.0f)
                {
                    // Increase the target count for the snake.
                    targetCounter += 1;

                    // Set target is hit to true;
                    targetIsHit = true;

                    // Set before runnig to false.
                    beforeRunning = false;
                }
            }

            // Get the player and target position for the display method.
            playerPosition = snakeBody->GetPosition();

            // Debug for distance.
            // cout << "\n[ Debug ] - > The distance is >> " << distance
               // << " << \n" << endl;

            // Display the code.
            display(target, playerPosition, targetIsHit);

            // Set running to false using brfor running.
            running = beforeRunning;

            if (running == false)
            {
                // Break the code;
                break;
            }
        }
    }

    // Inform the player the game is won.
    // Wait user input to continue.
    cout << "You have won the game! " << endl;
    cout << "Please enter KEY to end game! " << endl;
    input = _getch();
    

    // Delete heap;
    delete world;
    world = nullptr;

    delete target;
    target = nullptr;

    snakeBody = nullptr;

    wall1 = nullptr;
    wall2 = nullptr;
    wall3 = nullptr;
    wall4 = nullptr;

    // Check and erase memory leak.
    if (_CrtDumpMemoryLeaks())
    {
        // Print memory leaks is detected.
        cout << "Memory Leaks detected!" << endl;
        cout << "Please check debug!" << endl;
    }

    //// Create a window
    //RenderWindow window(VideoMode(800, 600), "My window");

    //// Run as long as window is open.
    //while (window.isOpen())
    //{
    //    // Check triggered events during last loop.
    //    Event event;
    //    while (window.pollEvent(event))
    //    {
    //        // If event is closed, close the window.
    //        if (event.type == Event::Closed)
    //        {
    //            window.close();
    //        }
    //    }

    //    // Clear the window with black colour.
    //    window.clear(Color::Black);

    //    // Draw all items here.

    //    // End the current frame.
    //    window.display();
    //}

    //return 0;
}

void update()
{
    // Create a time step using seconds that have passed.
    // Use delta time to update world step.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
