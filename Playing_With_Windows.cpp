// Playing_With_Windows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    // Create a window
    RenderWindow window(VideoMode(800, 600), "My window");

    // Create objects outside the loop.
    CircleShape circle(50);
    circle.setFillColor(Color(100, 0, 0));
    circle.setPosition(50 + 70, 50);

    CircleShape triangle(50, 3);
    triangle.setFillColor(Color::White);
    triangle.setPosition(200 + 60, 50);

    CircleShape square(50, 4);
    square.setFillColor(Color::Yellow);
    square.setPosition(350 + 60, 50);

    CircleShape pentagon(50, 5);
    pentagon.setFillColor(Color::Cyan);
    pentagon.setPosition(500 + 60, 50);

    // Run as long as window is open.
    while (window.isOpen())
    {
        // Check triggered events during last loop.
        Event event;
        while (window.pollEvent(event))
        {
            // If event is closed, close the window.
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window with black colour.
        window.clear(Color::Black);

        // Draw all items here.
        window.draw(circle);
        window.draw(triangle);
        window.draw(square);
        window.draw(pentagon);

        // End the current frame.
        window.display();
    }

    return 0;
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
