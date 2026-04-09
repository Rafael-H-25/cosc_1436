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
    return 0.5 * g * (seconds * seconds);
};

/// @brief Converts units of Meters to Feet
/// @param meter The automatic unit of length
/// @return Returns foot value
double convertMeterToFeet(double meter)
{
    return meter * 3.28084;
};

/// @brief Calculates velocity by the seconds given
/// @param seconds The time given by user
/// @return Returns the velocity
double calculateVelocity(int seconds)
{
    const double g = 9.8;
    const double terminalVelocity = 90.0;
    double velocity = g * seconds;
    if (velocity > terminalVelocity)
    {
        velocity = terminalVelocity;
    }
    return velocity;
};

/// @brief Displays program information
void displayProgramHeader()
{
    DisplayLine(50);
    std::cout << "      Falling Distance and Velocity Calculator        " << std::endl;
    DisplayLine(50);
    std::cout << "Programmer: Rafael Hernandez" << std::endl;
    std::cout << "Course: COSC 1436" << std::endl;
    std::cout << "Semester: Spring 2026" << std::endl;
    DisplayLine(50);
    std::cout << std::endl;
};

/// @brief Asks for a falling time number from 1 to 60.
/// @return Gives the inputed value from user
int getFallingTime()
{
    int time;
    std::cout << "Please enter falling time in seconds (1-60): ";
    
    while (!(std::cin >> time) || time < 1 || time > 60)
    {
        std::cout << "Problem: Invalid value. Please enter a value between 1 and 60: ";
        ClearInputBuffer();
    }
    return time;
};

/// @brief Displays the table of time, distance, and velocity per second
/// @param totalSeconds The total seconds given by user
/// @param choice The unit measurement chosen by user
/// @param unitLabel The units for distance. 
void displayDistanceTable(int totalSeconds, int choice, std::string unitLabel)
{   //Table Header
    DisplayLine(50);
    std::cout << std::left << std::setw(12) << "Seconds"
        << std::setw(22) << "Distance" 
    << std::setw(15) << "Velocity" << std::endl;
    DisplayLine(50);
    std::cout << std::fixed << std::setprecision(2);

    //The table rows per second
    for (int currentSecond = 1; currentSecond <= totalSeconds; currentSecond++)
    {
        double distance = calculateFallingDistance(currentSecond);  // 2nd row of information
        double velocity = calculateVelocity(currentSecond);         // 3rd row of information
        
        if (choice == 2)    // Converts meters to feet.
        {
            distance = convertMeterToFeet(distance);
        }

        std::cout << std::right << std::setw(4) << currentSecond << "s   "  // Shows units
            << std::setw(12) << distance << unitLabel << "   "
            << std::setw(12) << velocity << "m/s" << std::endl;
    }
    DisplayLine(50);
}

int main()
{
    displayProgramHeader();

    // Default choice
    int unitChoice;
    std::string unitName = "m";

    std::cout << "Select units:(1) Meters or (2) Feet: "; 
    while (!(std::cin >> unitChoice) || (unitChoice != 1 && unitChoice != 2))
    {
        std::cout << "Issue: Enter 1 or 2 for your measurement type." << std::endl;
        ClearInputBuffer();
    }

    if (unitChoice == 2)
    {
        unitName = "ft";
    }
    
    int seconds = getFallingTime();
    displayDistanceTable(seconds, unitChoice, unitName);
    
    return 0;
}