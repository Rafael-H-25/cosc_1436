/*
*   Lab 2
*   Rafael Hernandez
*   COSC 1436
*   Spring 2026
*/

#include <iostream>
#include <iomanip>
#include <string>

/// @brief Displays a horizontal line
/// @param width Width of a line
void DisplayLine(int width)
{
    std::cout << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << std::endl;
};

/// @brief  Clears the input buffer of extra characters and sentences
void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT32_MAX, '\n');
};

/// @brief Calculates the distance from time given
/// @param seconds The number of seconds given by user
/// @return Returns the distance value
double calculateFallingDistance(int seconds)
{
    const double g = 9.8;
    double distance = 0.5 * g * (seconds * seconds);
    return distance;
}

/// @brief Converts units of Meters to Feet
/// @param m M means meaters
/// @return Returns feet value
double convertMeterToFeet(double m)
{
    return m * 3.28084;
}

/// @brief Displays table of information of distance fallen per second
/// @param totalSeconds Total seconds
/// @param g Gravity number
/// @param unitLabel The unit chosen for data table
void displayDistanceTable(int totalSeconds, int choice, std::string unitLabel)
{   //Table Header
    DisplayLine(35);
    std::cout << std::left << std::setw(15) << "Seconds"
        << std::setw(15) << "Distance (" << unitLabel << ")" << std::endl;
    DisplayLine(35);

    std::cout << std::fixed << std::setprecision(2);

    //The table rows
    for (int currentSecond = 1; currentSecond <= totalSeconds; currentSecond++)
    {
        double distance = calculateFallingDistance(currentSecond);
        if (choice == 2)
        {
            distance = convertMeterToFeet(distance);
        }
 
        std::cout << std::left << std::setw(15) << currentSecond
            << std::setw(15) << distance << std::endl;
    }
    DisplayLine(32);
}

/// @brief Displays program information
void displayProgramHeader()
{
    std::cout << "FallingDistance" << std::endl;
    std::cout << "Programmer: Rafael Hernandez" << std::endl;
    std::cout << "Course: COSC 1436" << std::endl;
    std::cout << "Semester: Spring 2026" << std::endl;
};

/// @brief Asks for a falling time number from 1 to 60.
/// @return Gives the inputed value from user
int getFallingTime()
{
    int time;
    std::cout << "Please enter falling time in seconds (1-60): ";
    std::cin >> time;

    while (time < 1 || time > 60)
    {
        std::cout << "Problem: Invalid value. Please enter a value between 1 and 60: ";
        ClearInputBuffer();
        std::cin >> time;
    }
    return time;
};


int main()
{
    displayProgramHeader();

    // Default choice
    int unitChoice;
    std::string unitName = "m";

    std::cout << "Choose the unit:" << std::endl;
    std::cout << "1. Meters" << std::endl;
    std::cout << "2. Feet" << std::endl;
    std::cout << "Selected: "; 
    std::cin >> unitChoice;
    
    if (unitChoice == 2)
    {
        unitName = "feet";
    }
    
    int seconds = getFallingTime();

    displayDistanceTable(seconds, unitChoice, unitName);
    
    return 0;
}
