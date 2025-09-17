// Name: Mayowa Famade.
// Purpose: PE 2 Hello World.
// Date: 9/3/2024.

// Create an include IOstream file.
// Create an include "stdio.h" and cmath.
// Create a "funtions.h";
#include <iostream>
#include <stdio.h>
#include <cmath>
#include "funtions.h";

// Create a using std namespace.
using namespace std;

/// <summary>
/// This function finds the number of seconds
/// in the month of december.
/// </summary>
/// <returns>An integer.</returns>
static int SecondsInDecember()
{
    // Find the number of seconds in a month.
    int daysInMonth = 31;
    int hoursInday = 24;
    int minutesInHour = 60;
    int secondsInMinute = 60;

    // Find the result.
    int result =
        daysInMonth *
        hoursInday *
        minutesInHour *
        secondsInMinute;

    // Return the result.
    return result;
}

/// <summary>
/// This funtion finds the area of a given
/// circle using a given radius.
/// </summary>
/// <param name="radius">
/// The given circle radius.</param>
/// <returns>A double.</returns>
double AreaOfCircle(double radius)
{
    // Get the pi constant manually.
    const double PI = 3.14159265358979323846;

    // Get the power of radius.
    double square = pow(radius, 2);

    // Calculate area.
    double area = PI * square;

    // Return area.
    return area;
}

/// <summary>
/// This funtion divided two interger number
/// and returns the remainder.
/// </summary>
/// <param name="a">The first number.</param>
/// <param name="b">The second number</param>
/// <returns>A interger./returns>
int IntDivision(int a, int b)
{
    // Return the division
    return a / b;
}

int main()
{
    // Use Prinf to print letters.
    printf("Hello World!\n");

    // Get the area of a circle with radius
    // of 6.2.
    double circleArea = AreaOfCircle(6.2);

    // Get the division of int.
    int firstNumber = 5;
    int secondNumber = 2;
    int division = IntDivision(firstNumber,
        secondNumber);

    // Print out the area and division.
    printf("The area of 6.2 is %.2f\n", circleArea);

    // Print out the division.
    printf("%i / %i is %i",
        firstNumber,
        secondNumber,
        division);
}

